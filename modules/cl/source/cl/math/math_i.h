#pragma once

#include <cl/types.h>

// basic
s32 mabs(s32 x);

s32 msign(s32 x);

// bounding
s32 mmin(s32 x, s32 y);
u32 mmin(u32 x, u32 y);

s32 mmax(s32 x, s32 y);
u32 mmax(u32 x, u32 y);

s32 mclamp(s32 x, s32 min, s32 max);
u32 mclamp(u32 x, u32 min, u32 max);

s32 mwrap(s32 x, s32 max);
u32 mwrap(u32 x, u32 max);

s32 mwrap2(s32 x, s32 min, s32 max);
u32 mwrap2(u32 x, u32 min, u32 max);
