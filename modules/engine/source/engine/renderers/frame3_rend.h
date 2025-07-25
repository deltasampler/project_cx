#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct frame3_point_t {
    fvec3_t position;
    fvec3_t size;
    fvec3_t color;
};

struct frame3_rdata_t {
    darr_t<frame3_point_t> points;
    u32 vao;
    u32 vbo;
};

void frame3_rdata_new(frame3_rdata_t& rdata);
void frame3_rdata_build(frame3_rdata_t& rdata);
void frame3_rdata_clear(frame3_rdata_t& rdata);

void frame3_rend_init();
void frame3_rend_shut();
void frame3_rend_render(frame3_rdata_t& rdata, const cam3_t& cam);
