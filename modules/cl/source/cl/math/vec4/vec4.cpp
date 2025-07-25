#include <stdio.h>
#include <cl/math/math_r.h>
#include <cl/math/math_i.h>

// float
#include "struct_f.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "color.cpp"

// double
#include "struct_d.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "color.cpp"

// int
#include "struct_s.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// basic
void vec4_abs(vec4_t& out, const vec4_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
    out.z = mabs(v.z);
    out.w = mabs(v.w);
}

vec4_t vec4n_abs(const vec4_t& v) {
    vec4_t out;

    vec4_abs(out, v);

    return out;
}

void vec4m_abs(vec4_t& out) {
    vec4_abs(out, out);
}

void vec4_neg(vec4_t& out, const vec4_t& v) {
    out.x = -v.x;
    out.y = -v.y;
    out.z = -v.z;
    out.w = -v.w;
}

vec4_t vec4n_neg(const vec4_t& v) {
    vec4_t out;

    vec4_neg(out, v);

    return out;
}

void vec4m_neg(vec4_t& out) {
    vec4_neg(out, out);
}

// string
void vec4_str(const vec4_t& v, char* str) {
    sprintf(str, "vec4(%i, %i, %i, %i)", num_t(v.x), num_t(v.y), num_t(v.z), num_t(v.w));
}

// uint
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void vec4_str(const vec4_t& v, char* str) {
    sprintf(str, "vec4(%u, %u, %u, %u)", num_t(v.x), num_t(v.y), num_t(v.z), num_t(v.w));
}
