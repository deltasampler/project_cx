#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct arrow2_point_t {
    fvec3_t position;
    f32 size;
    fvec3_t normal;
    fvec3_t color;
};

struct arrow2_rdata_t {
    darr_t<arrow2_point_t> points;
    bool should_follow;
    u32 vao;
    u32 vbo;
};

void arrow2_rdata_new(arrow2_rdata_t& rdata);
void arrow2_rdata_build(arrow2_rdata_t& rdata);
void arrow2_rdata_clear(arrow2_rdata_t& rdata);

void arrow2_rend_init();
void arrow2_rend_shut();
void arrow2_rend_render(arrow2_rdata_t& rdata, const cam3_t& cam);
