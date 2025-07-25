#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec3_base_f.h>

struct arrow3_point_t {
    fvec3_t position;
    f32 size;
    fvec3_t color;
};

struct arrow3_rdata_t {
    darr_t<arrow3_point_t> points;
    u32 vao;
    u32 vbo;
};

void arrow3_rdata_new(arrow3_rdata_t& rdata);
void arrow3_rdata_build(arrow3_rdata_t& rdata);
void arrow3_rdata_clear(arrow3_rdata_t& rdata);

void arrow3_rend_init();
void arrow3_rend_shut();
void arrow3_rend_render(arrow3_rdata_t& rdata, const cam3_t& cam);
