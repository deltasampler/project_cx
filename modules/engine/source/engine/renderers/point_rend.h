#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct point_t {
    fvec3_t position;
    f32 size;
    fvec3_t color;
};

struct point_rdata_t {
    darr_t<point_t> points;
    u32 vao;
    u32 vbo;
};

void point_rdata_new(point_rdata_t& rdata);
void point_rdata_build(point_rdata_t& rdata);
void point_rdata_clear(point_rdata_t& rdata);

void point_rend_init();
void point_rend_shut();
void point_rend_render(point_rdata_t& rdata, const cam3_t& cam);
