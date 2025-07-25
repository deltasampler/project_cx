#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct line3_point_t {
    fvec3_t position;
    f32 size;
    fvec3_t color;
};

struct line3_rdata_t {
    darr_t<line3_point_t> points;
    u32 vao;
    u32 vbo;
};

void line3_rdata_new(line3_rdata_t& rdata);
void line3_rdata_build(line3_rdata_t& rdata);
void line3_rdata_clear(line3_rdata_t& rdata);

void line3_rend_init();
void line3_rend_shut();
void line3_rend_render(line3_rdata_t& rdata, const cam3_t& cam);
