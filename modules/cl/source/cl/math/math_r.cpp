#include <math.h>

#include "math_r.h"

// basic
f32 mabs(f32 x) {
    return fabsf(x);
}

f64 mabs(f64 x) {
    return fabs(x);
}

f32 msign(f32 x) {
    if (x < 0.0f) return -1.0f;
    if (x > 0.0f) return 1.0f;

    return 0.0f;
}

f64 msign(f64 x) {
    if (x < 0.0) return -1.0;
    if (x > 0.0) return 1.0;

    return 0.0;
}

f32 mfract(f32 x) {
    return x - floorf(x);
}

f64 mfract(f64 x) {
    return x - floor(x);
}

f32 mmod(f32 x, f32 y) {
    return fmodf(x, y);
}

f64 mmod(f64 x, f64 y) {
    return fmod(x, y);
}

// power
f32 mpow(f32 x, f32 y) {
    return powf(x, y);
}

f64 mpow(f64 x, f64 y) {
    return pow(x, y);
}

f32 msqrt(f32 x) {
    return sqrtf(x);
}

f64 msqrt(f64 x) {
    return sqrt(x);
}

f32 mcbrt(f32 x) {
    return cbrtf(x);
}

f64 mcbrt(f64 x) {
    return cbrt(x);
}

f32 mhypot(f32 x, f32 y) {
    return hypotf(x, y);
}

f64 mhypot(f64 x, f64 y) {
    return hypot(x, y);
}

f32 mhypot(f32 x, f32 y, f32 z) {
    return sqrtf(x * x + y * y + z * z);
}

f64 mhypot(f64 x, f64 y, f64 z) {
    return sqrt(x * x + y * y + z * z);
}

f32 mhypot(f32 x, f32 y, f32 z, f32 w) {
    return sqrtf(x * x + y * y + z * z + w * w);
}

f64 mhypot(f64 x, f64 y, f64 z, f64 w) {
    return sqrt(x * x + y * y + z * z + w * w);
}

f32 mhypot(f32 i0, f32 i1, f32 i2, f32 i3, f32 i4, f32 i5, f32 i6, f32 i7, f32 i8) {
    return sqrtf(i0 * i0 + i1 * i1 + i2 * i2 + i3 * i3 + i4 * i4 + i5 * i5 + i6 * i6 + i7 * i7 + i8 * i8);
}

f64 mhypot(f64 i0, f64 i1, f64 i2, f64 i3, f64 i4, f64 i5, f64 i6, f64 i7, f64 i8) {
    return sqrt(i0 * i0 + i1 * i1 + i2 * i2 + i3 * i3 + i4 * i4 + i5 * i5 + i6 * i6 + i7 * i7 + i8 * i8);
}

f32 mhypot(f32 i0, f32 i1, f32 i2, f32 i3, f32 i4, f32 i5, f32 i6, f32 i7, f32 i8, f32 i9, f32 i10, f32 i11, f32 i12, f32 f13, f32 f14, f32 f15) {
    return sqrtf(i0 * i0 + i1 * i1 + i2 * i2 + i3 * i3 + i4 * i4 + i5 * i5 + i6 * i6 + i7 * i7 + i8 * i8 + i9 * i9 + i10 * i10 + i11 * i11 + i12 * i12 + f13 * f13 + f14 * f14 + f15 * f15);
}

f64 mhypot(f64 i0, f64 i1, f64 i2, f64 i3, f64 i4, f64 i5, f64 i6, f64 i7, f64 i8, f64 i9, f64 i10, f64 i11, f64 i12, f64 f13, f64 f14, f64 f15) {
    return sqrt(i0 * i0 + i1 * i1 + i2 * i2 + i3 * i3 + i4 * i4 + i5 * i5 + i6 * i6 + i7 * i7 + i8 * i8 + i9 * i9 + i10 * i10 + i11 * i11 + i12 * i12 + f13 * f13 + f14 * f14 + f15 * f15);
}

// exponential
f32 mexp(f32 x) {
    return expf(x);
}

f64 mexp(f64 x) {
    return exp(x);
}

f32 mexp2(f32 x) {
    return exp2f(x);
}

f64 mexp2(f64 x) {
    return exp2(x);
}

f32 mlog(f32 x) {
    return logf(x);
}

f64 mlog(f64 x) {
    return log(x);
}

f32 mlog2(f32 x) {
    return log2f(x);
}

f64 mlog2(f64 x) {
    return log2(x);
}

f32 mlog10(f32 x) {
    return log10f(x);
}

f64 mlog10(f64 x) {
    return log10(x);
}

// angles
f32 mrad(f32 x) {
    return x * f32(PI) / 180.0f;
}

f64 mrad(f64 x) {
    return x * f64(PI) / 180.0;
}

f32 mdeg(f32 x) {
    return x * 180.0f / f32(PI);
}

f64 mdeg(f64 x) {
    return x * 180.0 / f64(PI);
}

// trigonometric
f32 msin(f32 x) {
    return sinf(x);
}

f64 msin(f64 x) {
    return sin(x);
}

f32 mcos(f32 x) {
    return cosf(x);
}

f64 mcos(f64 x) {
    return cos(x);
}

f32 mtan(f32 x) {
    return tanf(x);
}

f64 mtan(f64 x) {
    return tan(x);
}

f32 masin(f32 x) {
    return asinf(x);
}

f64 masin(f64 x) {
    return asin(x);
}

f32 macos(f32 x) {
    return acosf(x);
}

f64 macos(f64 x) {
    return acos(x);
}

f32 matan(f32 x) {
    return atanf(x);
}

f64 matan(f64 x) {
    return atan(x);
}

f32 matan2(f32 y, f32 x) {
    return atan2f(y, x);
}

f64 matan2(f64 y, f64 x) {
    return atan2(y, x);
}

// hyperbolic
f32 msinh(f32 x) {
    return sinhf(x);
}

f64 msinh(f64 x) {
    return sinh(x);
}

f32 mcosh(f32 x) {
    return coshf(x);
}

f64 mcosh(f64 x) {
    return cosh(x);
}

f32 mtanh(f32 x) {
    return tanhf(x);
}

f64 mtanh(f64 x) {
    return tanh(x);
}

f32 masinh(f32 x) {
    return asinhf(x);
}

f64 masinh(f64 x) {
    return asinh(x);
}

f32 macosh(f32 x) {
    return acoshf(x);
}

f64 macosh(f64 x) {
    return acosh(x);
}

f32 matanh(f32 x) {
    return atanhf(x);
}

f64 matanh(f64 x) {
    return atanh(x);
}

// rounding
f32 mtrunc(f32 x) {
    return truncf(x);
}

f64 mtrunc(f64 x) {
    return trunc(x);
}

f32 mfloor(f32 x) {
    return floorf(x);
}

f64 mfloor(f64 x) {
    return floor(x);
}

f32 mceil(f32 x) {
    return ceilf(x);
}

f64 mceil(f64 x) {
    return ceil(x);
}

f32 mround(f32 x) {
    return roundf(x);
}

f64 mround(f64 x) {
    return round(x);
}

f32 mround2(f32 x, f32 y) {
    f32 f = powf(10.0f, y);

    return roundf(x * f) / f;
}

f64 mround2(f64 x, f64 y) {
    f64 f = pow(10.0, y);

    return round(x * f) / f;
}

f32 msnap(f32 x, f32 y) {
    return roundf(x / y) * y;
}

f64 msnap(f64 x, f64 y) {
    return round(x / y) * y;
}

// bounding
f32 mmin(f32 x, f32 y) {
    return fminf(x, y);
}

f64 mmin(f64 x, f64 y) {
    return fmin(x, y);
}

f32 mmax(f32 x, f32 y) {
    return fmaxf(x, y);
}

f64 mmax(f64 x, f64 y) {
    return fmax(x, y);
}

f32 mclamp(f32 x, f32 min, f32 max) {
    return fminf(fmaxf(x, min), max);
}

f64 mclamp(f64 x, f64 min, f64 max) {
    return fmin(fmax(x, min), max);
}

f32 mwrap(f32 x, f32 max) {
    return fmodf(x + max, max);
}

f64 mwrap(f64 x, f64 max) {
    return fmod(x + max, max);
}

f32 mwrap2(f32 x, f32 min, f32 max) {
    float r = max - min;

    return fmodf(fmodf(x - min, r) + r, r) + min;
}

f64 mwrap2(f64 x, f64 min, f64 max) {
    float r = max - min;

    return fmod(fmod(x - min, r) + r, r) + min;
}

// interpolation
f32 mlerp(f32 x, f32 y, f32 t) {
    return x + t * (y - x);
}

f64 mlerp(f64 x, f64 y, f64 t) {
    return x + t * (y - x);
}

f32 mlerp2(f32 x, f32 y, f32 t) {
    return x * (1.0f - t) + y * t;
}

f64 mlerp2(f64 x, f64 y, f64 t) {
    return x * (1.0 - t) + y * t;
}

// stepping
f32 mstep(f32 x, f32 e) {
    if (x < e) return 0.0f;

    return 1.0f;
}

f64 mstep(f64 x, f64 e) {
    if (x < e) return 0.0;

    return 1.0;
}

f32 msmoothstep(f32 x, f32 e0, f32 e1) {
    if (x <= e0) return 0.0f;
    if (x >= e1) return 1.0f;

    f32 t = (x - e0) / (e1 - e0);

    return t * t * (3.0f - 2.0f * t);
}

f64 msmoothstep(f64 x, f64 e0, f64 e1) {
    if (x <= e0) return 0.0;
    if (x >= e1) return 1.0;

    f64 t = (x - e0) / (e1 - e0);

    return t * t * (3.0 - 2.0 * t);
}
