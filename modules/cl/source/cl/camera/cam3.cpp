#include <cl/math/vec3_base_f.h>
#include <cl/math/mat4_base_f.h>
#include <cl/math/mat4_transf_f.h>
#include <cl/math/math_r.h>

#include "cam3.h"

cam3_t cam3_new() {
    cam3_t cam;

    cam.position = fvec3();
    cam.forward = fvec3(0.0f, 0.0f, -1.0f);
    cam.right = fvec3(1.0f, 0.0f, 0.0f);
    cam.up = fvec3(0.0f, 1.0f, 0.0f);
    cam.world_up = fvec3(0.0f, 1.0f, 0.0f);
    cam.projection = fmat4(1.0f);
    cam.view = fmat4(1.0f);
    cam.near = 0.01f;
    cam.far = 1000.0f;
    cam.fov = 90.0f;
    cam.yaw = 0.0f;
    cam.pitch = 0.0f;
    cam.roll = 0.0f;
    cam.movement_speed = 0.1f;
    cam.yaw_speed = 0.1f;
    cam.pitch_speed = 0.1f;
    cam.roll_speed = 0.1f;
    cam.zoom_speed = 0.1f;

    return cam;
}

void cam3_move_forward(cam3_t& cam, f32 dir) {
    vec3m_addmuls(cam.position, cam.forward, cam.movement_speed * dir);
}

void cam3_move_right(cam3_t& cam, f32 dir) {
    vec3m_addmuls(cam.position, cam.right, cam.movement_speed * dir);
}

void cam3_move_up(cam3_t& cam, f32 dir) {
    vec3m_addmuls(cam.position, cam.up, cam.movement_speed * dir);
}

void cam3_pan(cam3_t& cam, f32 dir) {
    cam.yaw += cam.yaw_speed * dir;
}

void cam3_tilt(cam3_t& cam, f32 dir) {
    cam.pitch = mclamp(cam.pitch - cam.pitch_speed * dir, -89.0f, 89.0f);
}

void cam3_roll(cam3_t& cam, f32 dir) {
    cam.roll += cam.roll_speed * dir;
}

void cam3_zoom(cam3_t& cam, f32 dir) {
    cam.fov += cam.zoom_speed * dir;
}

void cam3_fru(cam3_t& cam) {
    cam.forward = vec3n_unit(fvec3(
        msin(mrad(cam.yaw)) * mcos(mrad(cam.pitch)),
        msin(mrad(cam.pitch)),
        -mcos(mrad(cam.yaw)) * mcos(mrad(cam.pitch))
    ));

    cam.right = vec3n_unit(vec3n_cross(cam.forward, cam.world_up));

    cam.up = vec3n_unit(vec3n_cross(cam.right, cam.forward));
}

void cam3_compute_proj(cam3_t& cam, s32 viewport_x, s32 viewport_y) {
    mat4_perspective(cam.projection, mrad(cam.fov), f32(viewport_x) / f32(viewport_y), cam.near, cam.far);
}

void cam3_compute_view(cam3_t& cam) {
    mat4_look_at(cam.view, cam.position, vec3n_add(cam.position, cam.forward), cam.up);
}
