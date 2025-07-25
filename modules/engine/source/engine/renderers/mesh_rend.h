#pragma once

#include <cl/camera/cam3.h>
#include <cl/data/darr.h>
#include <cl/math/vec2_base_f.h>
#include <cl/math/vec3_base_f.h>
#include "sky_rend.h"

struct vertex_t {
    fvec3_t position;
    fvec3_t normal;
    fvec2_t tex_coord;
    fvec3_t color;
};

struct mesh_rdata_t {
    darr_t<vertex_t> vertices;
    darr_t<u32> indices;
    u32 vao;
    u32 vbo;
    u32 ebo;
};

void mesh_rdata_new(mesh_rdata_t& rdata);
void mesh_rdata_build(mesh_rdata_t& rdata);
void mesh_rdata_clear(mesh_rdata_t& rdata);

void mesh_rend_init();
void mesh_rend_shut();
void mesh_rend_render(mesh_rdata_t& rdata, const cam3_t& cam, const sky_rdata_t& sky_rdata);
