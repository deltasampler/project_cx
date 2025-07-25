#include <glad/gl.h>
#include <imgui/imgui.h>
#include <gl/shader.h>
#include <cl/math/math_r.h>
#include <cl/math/vec3_base_f.h>
#include <cl/math/vec3_color_f.h>
#include <cl/math/vec4_base_f.h>
#include <stdio.h>

#ifndef MODULE_PATH
#define MODULE_PATH "./"
#endif

#include "ray_marcher.h"

static u32 main_texture;
static u32 collision_texture;
static u32 vao;
static u32 vbo;
static s32 width = 0;
static s32 height = 0;

s32 march_limit = 512;
s32 shadow_limit = 64;
fvec3_t light_dir = {1.0f, 1.0f, 1.0f};
fvec3_t light_color = frgb(255, 252, 207);
fvec3_t sky_low_color = frgb(156, 179, 229);
fvec3_t sky_high_color = frgb(69, 102, 190);
f32 ambient_stren = 0.1f;
f32 specular_stren = 0.3f;
f32 sun_size = 0.1f;
s32 aa_samples = 1;
s32 fract_iter = 16;

f32 fract_scaling = 1.473f;
fvec3_t fract_rotation = {0.0f, 0.0f, 0.0f};
fvec3_t fract_translation = {-10.27f, 3.28f, -1.9f};
fvec3_t fract_color = {1.17f, 0.07f, 1.27f};

f32 radius = 0.005;

static struct {
    u32 handle;
    s32 u_projection;
    s32 u_view;
    s32 u_march_limit;
    s32 u_shadow_limit;
    s32 u_near;
    s32 u_far;
    s32 u_light_dir;
    s32 u_light_color;
    s32 u_sky_low_color;
    s32 u_sky_high_color;
    s32 u_fract_translation;
    s32 u_fract_rotation;
    s32 u_fract_scaling;
    s32 u_fract_color;
    s32 u_time;
    s32 u_ambient_stren;
    s32 u_specular_stren;
    s32 u_sun_size;
    s32 u_aa_samples;
    s32 u_fract_iter;
} main_shader;

static struct {
    u32 handle;
} output_shader;

static struct {
    u32 handle;
    s32 u_projection;
    s32 u_view;
    s32 u_fract_translation;
    s32 u_fract_rotation;
    s32 u_fract_scaling;
    s32 u_time;
    s32 u_fract_iter;
    s32 u_radius;
} collision_shader;

void ray_marcher_init(s32 w, s32 h) {
    width = w;
    height = h;

    main_shader.handle = program_load(MODULE_PATH"assets/shaders/ray_marcher/main.glsl");
    main_shader.u_projection = glGetUniformLocation(main_shader.handle, "u_projection");
    main_shader.u_view = glGetUniformLocation(main_shader.handle, "u_view");
    main_shader.u_march_limit = glGetUniformLocation(main_shader.handle, "u_march_limit");
    main_shader.u_shadow_limit = glGetUniformLocation(main_shader.handle, "u_shadow_limit");
    main_shader.u_near = glGetUniformLocation(main_shader.handle, "u_near");
    main_shader.u_far = glGetUniformLocation(main_shader.handle, "u_far");
    main_shader.u_light_dir = glGetUniformLocation(main_shader.handle, "u_light_dir");
    main_shader.u_light_color = glGetUniformLocation(main_shader.handle, "u_light_color");
    main_shader.u_sky_low_color = glGetUniformLocation(main_shader.handle, "u_sky_low_color");
    main_shader.u_sky_high_color = glGetUniformLocation(main_shader.handle, "u_sky_high_color");
    main_shader.u_fract_translation = glGetUniformLocation(main_shader.handle, "u_fract_translation");
    main_shader.u_fract_rotation = glGetUniformLocation(main_shader.handle, "u_fract_rotation");
    main_shader.u_fract_scaling = glGetUniformLocation(main_shader.handle, "u_fract_scaling");
    main_shader.u_fract_color = glGetUniformLocation(main_shader.handle, "u_fract_color");
    main_shader.u_time = glGetUniformLocation(main_shader.handle, "u_time");
    main_shader.u_ambient_stren = glGetUniformLocation(main_shader.handle, "u_ambient_stren");
    main_shader.u_specular_stren = glGetUniformLocation(main_shader.handle, "u_specular_stren");
    main_shader.u_sun_size = glGetUniformLocation(main_shader.handle, "u_sun_size");
    main_shader.u_aa_samples = glGetUniformLocation(main_shader.handle, "u_aa_samples");
    main_shader.u_fract_iter = glGetUniformLocation(main_shader.handle, "u_fract_iter");

    output_shader.handle = program_load(MODULE_PATH"assets/shaders/ray_marcher/output.glsl");

    collision_shader.handle = program_load(MODULE_PATH"assets/shaders/ray_marcher/collision.glsl");
    collision_shader.u_projection = glGetUniformLocation(collision_shader.handle, "u_projection");
    collision_shader.u_view = glGetUniformLocation(collision_shader.handle, "u_view");
    collision_shader.u_fract_translation = glGetUniformLocation(collision_shader.handle, "u_fract_translation");
    collision_shader.u_fract_rotation = glGetUniformLocation(collision_shader.handle, "u_fract_rotation");
    collision_shader.u_fract_scaling = glGetUniformLocation(collision_shader.handle, "u_fract_scaling");
    collision_shader.u_time = glGetUniformLocation(collision_shader.handle, "u_time");
    collision_shader.u_fract_iter = glGetUniformLocation(collision_shader.handle, "u_fract_iter");
    collision_shader.u_radius = glGetUniformLocation(collision_shader.handle, "u_radius");

    glGenTextures(1, &main_texture);
    glBindTexture(GL_TEXTURE_2D, main_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenTextures(1, &collision_texture);
    glBindTexture(GL_TEXTURE_2D, collision_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, 1, 1, 0, GL_RGBA, GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void ray_marcher_shut() {

}

void ray_marcher_update(cam3_t& cam) {
    glUseProgram(collision_shader.handle);
    glUniformMatrix4fv(collision_shader.u_projection, 1, false, cam.projection.arr);
    glUniformMatrix4fv(collision_shader.u_view, 1, false, cam.view.arr);
    glUniform3fv(collision_shader.u_fract_translation, 1, fract_translation.arr);
    glUniform3fv(collision_shader.u_fract_rotation, 1, fract_rotation.arr);
    glUniform1f(collision_shader.u_fract_scaling, fract_scaling);
    glUniform1f(collision_shader.u_time, 0.0f);
    glUniform1i(collision_shader.u_fract_iter, fract_iter);
    glUniform1f(collision_shader.u_radius, radius);

    glBindTexture(GL_TEXTURE_2D, collision_texture);
    glBindImageTexture(1, collision_texture, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);

    glDispatchCompute(1, 1, 1);
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

    fvec4_t result = fvec4();
    glBindTexture(GL_TEXTURE_2D, collision_texture);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, result.arr);

    vec4_print(result);

    if (result.w < 0.0f) {
        cam.position += fvec3(result.x * result.w, result.y * result.w, result.z * result.w);
    }
}

void ray_marcher_render(cam3_t& cam) {
    glUseProgram(main_shader.handle);
    glUniformMatrix4fv(main_shader.u_projection, 1, false, cam.projection.arr);
    glUniformMatrix4fv(main_shader.u_view, 1, false, cam.view.arr);
    glUniform1f(main_shader.u_march_limit, (f32)march_limit);
    glUniform1f(main_shader.u_shadow_limit, (f32)shadow_limit);
    glUniform1f(main_shader.u_near, cam.near);
    glUniform1f(main_shader.u_far, cam.far);
    glUniform3fv(main_shader.u_light_dir, 1, light_dir.arr);
    glUniform3fv(main_shader.u_light_color, 1, light_color.arr);
    glUniform3fv(main_shader.u_sky_low_color, 1, sky_low_color.arr);
    glUniform3fv(main_shader.u_sky_high_color, 1, sky_high_color.arr);
    glUniform3fv(main_shader.u_fract_translation, 1, fract_translation.arr);
    glUniform3fv(main_shader.u_fract_rotation, 1, fract_rotation.arr);
    glUniform1f(main_shader.u_fract_scaling, fract_scaling);
    glUniform3fv(main_shader.u_fract_color, 1, fract_color.arr);
    glUniform1f(main_shader.u_time, 0.0f);
    glUniform1f(main_shader.u_ambient_stren, ambient_stren);
    glUniform1f(main_shader.u_specular_stren, specular_stren);
    glUniform1f(main_shader.u_sun_size, sun_size);
    glUniform1i(main_shader.u_aa_samples, aa_samples);
    glUniform1i(main_shader.u_fract_iter, fract_iter);

    glBindTexture(GL_TEXTURE_2D, main_texture);
    glBindImageTexture(0, main_texture, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
    glDispatchCompute((u32)mceil(width / 32.0f), (u32)mceil(height / 32.0f), 1);

    glUseProgram(output_shader.handle);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void ray_marcher_render_gui() {
    // if (ImGui::CollapsingHeader("Ray Marcher")) {
    //     ImGui::DragFloat("Radius", &radius, 0.01f);
    //     ImGui::DragFloat("Downscaling", &downscaling, 0.01f);
    //     ImGui::SliderInt("Limmit", &limit, 1, 512);
    //     ImGui::SliderInt("Iterations", &iterations, 1, 12);
    //     ImGui::DragFloat3("Light Position", light_position.arr, 0.01f);
    //     ImGui::ColorEdit3("Light Color", light_color.arr);
    //     ImGui::ColorEdit3("Ambient Color", ambient_color.arr);
    //     ImGui::DragFloat("Ambient Strength", &ambient_strength, 0.01f);
    //     ImGui::DragFloat3("Offset", offset.arr, 0.01f);
    //     ImGui::DragFloat3("Angle", angle.arr, 0.01f);
    //     ImGui::DragFloat3("Scale", scale.arr, 0.01f);
    // }
}
