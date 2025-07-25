#include <math.h>

#include "math_i.h"

// basic
s32 mabs(s32 x) {
    return abs(x);
}

s32 msign(s32 x) {
    if (x < 0) return -1;
    if (x > 0) return 1;

    return 0;
}

// bounding
s32 mmin(s32 x, s32 y) {
    return x < y ? x : y;
}

u32 mmin(u32 x, u32 y) {
    return x < y ? x : y;
}

s32 mmax(s32 x, s32 y) {
    return x > y ? x : y;
}

u32 mmax(u32 x, u32 y) {
    return x > y ? x : y;
}

s32 mclamp(s32 x, s32 min, s32 max) {
    return mmin(mmax(x, min), max);
}

u32 mclamp(u32 x, u32 min, u32 max) {
    return mmin(mmax(x, min), max);
}

s32 mwrap(s32 x, s32 max) {
    return (x + max) % max;
}

u32 mwrap(u32 x, u32 max) {
    return (x + max) % max;
}

s32 mwrap2(s32 x, s32 min, s32 max) {
    s32 r = max - min;

    if (r == 0) return min;

    return ((x - min) % r + r) % r + min;
}

u32 mwrap2(u32 x, u32 min, u32 max) {
    u32 r = max - min;

    if (r == 0) return min;

    return ((x - min) % r) + min;
}
