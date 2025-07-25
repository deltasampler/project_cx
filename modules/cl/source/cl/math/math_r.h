#pragma once

#include <cl/types.h>

// constants
#define EPSILON 0.000001
#define PI 3.141592653589793

// basic
f32 mabs(f32 x);
f64 mabs(f64 x);

f32 msign(f32 x);
f64 msign(f64 x);

f32 mfract(f32 x);
f64 mfract(f64 x);

f32 mmod(f32 x, f32 y);
f64 mmod(f64 x, f64 y);

// power
f32 mpow(f32 x, f32 y);
f64 mpow(f64 x, f64 y);

f32 msqrt(f32 x);
f64 msqrt(f64 x);

f32 mcbrt(f32 x);
f64 mcbrt(f64 x);

f32 mhypot(f32 x, f32 y);
f64 mhypot(f64 x, f64 y);

f32 mhypot(f32 x, f32 y, f32 z);
f64 mhypot(f64 x, f64 y, f64 z);

f32 mhypot(f32 x, f32 y, f32 z, f32 w);
f64 mhypot(f64 x, f64 y, f64 z, f64 w);

f32 mhypot(f32 i0, f32 i1, f32 i2, f32 i3, f32 i4, f32 i5, f32 i6, f32 i7, f32 i8);
f64 mhypot(f64 i0, f64 i1, f64 i2, f64 i3, f64 i4, f64 i5, f64 i6, f64 i7, f64 i8);

f32 mhypot(f32 i0, f32 i1, f32 i2, f32 i3, f32 i4, f32 i5, f32 i6, f32 i7, f32 i8, f32 i9, f32 i10, f32 i11, f32 i12, f32 f13, f32 f14, f32 f15);
f64 mhypot(f64 i0, f64 i1, f64 i2, f64 i3, f64 i4, f64 i5, f64 i6, f64 i7, f64 i8, f64 i9, f64 i10, f64 i11, f64 i12, f64 f13, f64 f14, f64 f15);

// exponential
f32 mexp(f32 x);
f64 mexp(f64 x);

f32 mexp2(f32 x);
f64 mexp2(f64 x);

f32 mlog(f32 x);
f64 mlog(f64 x);

f32 mlog2(f32 x);
f64 mlog2(f64 x);

f32 mlog10(f32 x);
f64 mlog10(f64 x);

// angles
f32 mrad(f32 x);
f64 mrad(f64 x);

f32 mdeg(f32 x);
f64 mdeg(f64 x);

// trigonometric
f32 msin(f32 x);
f64 msin(f64 x);

f32 mcos(f32 x);
f64 mcos(f64 x);

f32 mtan(f32 x);
f64 mtan(f64 x);

f32 masin(f32 x);
f64 masin(f64 x);

f32 macos(f32 x);
f64 macos(f64 x);

f32 matan(f32 x);
f64 matan(f64 x);

f32 matan2(f32 y, f32 x);
f64 matan2(f64 y, f64 x);

// hyperbolic
f32 msinh(f32 x);
f64 msinh(f64 x);

f32 mcosh(f32 x);
f64 mcosh(f64 x);

f32 mtanh(f32 x);
f64 mtanh(f64 x);

f32 masinh(f32 x);
f64 masinh(f64 x);

f32 macosh(f32 x);
f64 macosh(f64 x);

f32 matanh(f32 x);
f64 matanh(f64 x);

// rounding
f32 mtrunc(f32 x);
f64 mtrunc(f64 x);

f32 mfloor(f32 x);
f64 mfloor(f64 x);

f32 mceil(f32 x);
f64 mceil(f64 x);

f32 mround(f32 x);
f64 mround(f64 x);

f32 mround2(f32 x, f32 y);
f64 mround2(f64 x, f64 y);

f32 msnap(f32 x, f32 y);
f64 msnap(f64 x, f64 y);

// bounding
f32 mmin(f32 x, f32 y);
f64 mmin(f64 x, f64 y);

f32 mmax(f32 x, f32 y);
f64 mmax(f64 x, f64 y);

f32 mclamp(f32 x, f32 min, f32 max);
f64 mclamp(f64 x, f64 min, f64 max);

f32 mwrap(f32 x, f32 max);
f64 mwrap(f64 x, f64 max);

f32 mwrap2(f32 x, f32 min, f32 max);
f64 mwrap2(f64 x, f64 min, f64 max);

// interpolation
f32 mlerp(f32 x, f32 y, f32 t);
f64 mlerp(f64 x, f64 y, f64 t);

f32 mlerp2(f32 x, f32 y, f32 t);
f64 mlerp2(f64 x, f64 y, f64 t);

// stepping
f32 mstep(f32 x, f32 e);
f64 mstep(f64 x, f64 e);

f32 msmoothstep(f32 x, f32 e0, f32 e1);
f64 msmoothstep(f64 x, f64 e0, f64 e1);
