#pragma once

#include <cl/types.h>
#include <cl/camera/cam3.h>

void ray_marcher_init(s32 w, s32 h);
void ray_marcher_shut();
void ray_marcher_update(cam3_t& cam);
void ray_marcher_render(cam3_t& cam);
void ray_marcher_render_gui();
