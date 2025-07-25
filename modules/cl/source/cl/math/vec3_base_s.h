#pragma once

#include "vec3/struct_s.h"
#include "vec3/base.h"
#include "vec3/int.h"

// basic
void vec3_abs(vec3_t& out, const vec3_t& v);
vec3_t vec3n_abs(const vec3_t& out);
void vec3m_abs(vec3_t& out);

void vec3_neg(vec3_t& out, const vec3_t& v);
vec3_t vec3n_neg(const vec3_t& out);
void vec3m_neg(vec3_t& out);
