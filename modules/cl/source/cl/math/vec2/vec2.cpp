#include <stdio.h>
#include <cl/math/math_r.h>
#include <cl/math/math_i.h>

// float
#include "struct_f.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"

// double
#include "struct_d.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"

// int
#include "struct_s.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// basic
void vec2_abs(vec2_t& out, const vec2_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
}

vec2_t vec2n_abs(const vec2_t& v) {
    vec2_t out;

    vec2_abs(out, v);

    return out;
}

void vec2m_abs(vec2_t& out) {
    vec2_abs(out, out);
}

void vec2_neg(vec2_t& out, const vec2_t& v) {
    out.x = -v.x;
    out.y = -v.y;
}

vec2_t vec2n_neg(const vec2_t& v) {
    vec2_t out;

    vec2_neg(out, v);

    return out;
}

void vec2m_neg(vec2_t& out) {
    vec2_neg(out, out);
}

// string
void vec2_str(const vec2_t& v, char* str) {
    sprintf(str, "vec2(%i, %i)", num_t(v.x), num_t(v.y));
}

// uint
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void vec2_str(const vec2_t& v, char* str) {
    sprintf(str, "vec2(%u, %u)", num_t(v.x), num_t(v.y));
}
