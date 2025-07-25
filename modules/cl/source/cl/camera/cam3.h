#pragma once

#include <cl/math/vec3/struct_f.h>
#include <cl/math/mat4/struct_f.h>

struct cam3_t {
    fvec3_t position;
    fvec3_t forward;
    fvec3_t right;
    fvec3_t up;
    fvec3_t world_up;
    fmat4_t projection;
    fmat4_t view;
    f32 near;
    f32 far;
    f32 fov;
    f32 yaw;
    f32 pitch;
    f32 roll;
    f32 movement_speed;
    f32 yaw_speed;
    f32 pitch_speed;
    f32 roll_speed;
    f32 zoom_speed;
};

cam3_t cam3_new();

void cam3_move_forward(cam3_t& cam, f32 dir);
void cam3_move_right(cam3_t& cam, f32 dir);
void cam3_move_up(cam3_t& cam, f32 dir);

void cam3_pan(cam3_t& cam, f32 dir);
void cam3_tilt(cam3_t& cam, f32 dir);
void cam3_roll(cam3_t& cam, f32 dir);

void cam3_zoom(cam3_t& cam, f32 dir);

void cam3_fru(cam3_t& cam);

void cam3_compute_proj(cam3_t& cam, s32 viewport_x, s32 viewport_y);
void cam3_compute_view(cam3_t& cam);
