#pragma once

#include <cl/camera/cam3.h>
#include <cl/math/vec3/struct_f.h>
#include <cl/math/vec3_color_f.h>

struct sky_rdata_t {
    fvec3_t bottom_color = frgb(37.0f, 11.0f, 38.0f);
    fvec3_t middle_color = frgb(200.0f, 231.0f, 229.0f);
    fvec3_t top_color = frgb(0.0f, 94.0f, 246.0f);
    f32 sun_scale = 0.002f;
    fvec3_t sun_direction = {1.0f, 1.0f, 1.0f};
    fvec3_t sun_color = frgb(246.0f, 194.0f, 99.0f);
};

void sky_rend_init();
void sky_rend_shut();
void sky_rend_render(sky_rdata_t& sky, cam3_t& camera);
void sky_rend_imgui(sky_rdata_t& sky);
