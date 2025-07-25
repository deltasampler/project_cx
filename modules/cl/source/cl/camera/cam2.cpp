#include <cl/math/vec2_base_f.h>
#include <cl/math/vec3_base_f.h>
#include <cl/math/mat4_base_f.h>
#include <cl/math/mat4_transf_f.h>

#include "cam2.h"

cam2_t cam2_new() {
    cam2_t cam;

    cam.position = fvec2();
    cam.right = fvec2(1.0f, 0.0f);
    cam.up = fvec2(0.0f, 1.0f);
    cam.world_up = fvec2(0.0f, 1.0f);
    cam.projection = fmat4(1.0f);
    cam.near = -100.0f;
    cam.far = 100.0f;
    cam.view = fmat4(1.0f);
    cam.scale = 50.0f;
    cam.roll = 0.0f;
    cam.movement_speed = 0.1f;
    cam.roll_speed = 0.1f;
    cam.zoom_speed = 0.1f;

    return cam;
}

void cam2_move_right(cam2_t& cam, f32 dir) {
    vec2m_addmuls(cam.position, cam.right, cam.movement_speed * dir);
}

void cam2_move_up(cam2_t& cam, f32 dir) {
    vec2m_addmuls(cam.position, cam.up, cam.movement_speed * dir);
}

void cam2_roll(cam2_t& cam, f32 dir) {
    cam.roll += cam.roll_speed * dir;
}

void cam2_zoom(cam2_t& cam, f32 dir) {
    cam.scale += cam.zoom_speed * dir;
}

void cam2_compute_proj(cam2_t& cam, s32 viewport_x, s32 viewport_y) {
    mat4_ident(cam.projection);
    mat4_scale(cam.projection, cam.projection, fvec3(cam.scale / f32(viewport_x), cam.scale / f32(viewport_y), 1.0f));
}

void cam2_compute_view(cam2_t& cam) {
    mat4_ident(cam.view);
    mat4_translate(cam.view, cam.view, fvec3(-cam.position.x, -cam.position.y, 0.0f));
}
