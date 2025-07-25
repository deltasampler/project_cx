#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct line2_point_t {
    fvec3_t position;
    f32 size;
    fvec3_t normal;
    fvec3_t color;
};

struct line2_rdata_t {
    darr_t<line2_point_t> points;
    bool should_follow;
    u32 vao;
    u32 vbo;
};

void line2_rdata_new(line2_rdata_t& rdata);
void line2_rdata_build(line2_rdata_t& rdata);
void line2_rdata_clear(line2_rdata_t& rdata);

void line2_rend_init();
void line2_rend_shut();
void line2_rend_render(line2_rdata_t& rdata, const cam3_t& cam);
