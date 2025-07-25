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
void vec3_abs(vec3_t& out, const vec3_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
    out.z = mabs(v.z);
}

vec3_t vec3n_abs(const vec3_t& v) {
    vec3_t out;

    vec3_abs(out, v);

    return out;
}

void vec3m_abs(vec3_t& out) {
    vec3_abs(out, out);
}

void vec3_neg(vec3_t& out, const vec3_t& v) {
    out.x = -v.x;
    out.y = -v.y;
    out.z = -v.z;
}

vec3_t vec3n_neg(const vec3_t& v) {
    vec3_t out;

    vec3_neg(out, v);

    return out;
}

void vec3m_neg(vec3_t& out) {
    vec3_neg(out, out);
}

// string
void vec3_str(const vec3_t& v, char* str) {
    sprintf(str, "vec3(%i, %i, %i)", num_t(v.x), num_t(v.y), num_t(v.z));
}

// uint
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void vec3_str(const vec3_t& v, char* str) {
    sprintf(str, "vec3(%u, %u, %u)", num_t(v.x), num_t(v.y), num_t(v.z));
}
