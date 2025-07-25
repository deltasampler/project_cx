#include <glad/gl.h>
#include <imgui/imgui.h>
#include <gl/shader.h>

#ifndef MODULE_PATH
#define MODULE_PATH "./"
#endif

#include "sky_rend.h"

static u32 program;
static s32 u_projection;
static s32 u_view;
static s32 u_bottom_color;
static s32 u_middle_color;
static s32 u_top_color;
static s32 u_sun_direction;
static s32 u_sun_scale;
static s32 u_sun_color;

static u32 vao;

void sky_rend_init() {
    program = program_load(MODULE_PATH"assets/shaders/sky_rend.glsl");
    u_projection = glGetUniformLocation(program, "u_projection");
    u_view = glGetUniformLocation(program, "u_view");
    u_bottom_color = glGetUniformLocation(program, "u_bottom_color");
    u_middle_color = glGetUniformLocation(program, "u_middle_color");
    u_top_color = glGetUniformLocation(program, "u_top_color");
    u_sun_direction = glGetUniformLocation(program, "u_sun_direction");
    u_sun_scale = glGetUniformLocation(program, "u_sun_scale");
    u_sun_color = glGetUniformLocation(program, "u_sun_color");

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void sky_rend_shut() {
    glDeleteProgram(program);
    glDeleteVertexArrays(1, &vao);
}

void sky_rend_render(sky_rdata_t& sky, cam3_t& camera) {
    glUseProgram(program);
    glUniformMatrix4fv(u_projection, 1, false, camera.projection.arr);
    glUniformMatrix4fv(u_view, 1, false, camera.view.arr);
    glUniform3fv(u_bottom_color, 1, sky.bottom_color.arr);
    glUniform3fv(u_middle_color, 1, sky.middle_color.arr);
    glUniform3fv(u_top_color, 1, sky.top_color.arr);
    glUniform1f(u_sun_scale, sky.sun_scale);
    glUniform3fv(u_sun_direction, 1, sky.sun_direction.arr);
    glUniform3fv(u_sun_color, 1, sky.sun_color.arr);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void sky_rend_imgui(sky_rdata_t& sky) {
    if (ImGui::CollapsingHeader("Sky")) {
        ImGui::ColorEdit3("Bottom Color", sky.bottom_color.arr);
        ImGui::ColorEdit3("Middle Color", sky.middle_color.arr);
        ImGui::ColorEdit3("Top Color", sky.top_color.arr);
        ImGui::DragFloat("Sun Scale", &sky.sun_scale, 0.001f);
        ImGui::DragFloat3("Sun Direction", sky.sun_direction.arr, 0.001f);
        ImGui::ColorEdit3("Sun Color", sky.sun_color.arr);
    }
}
