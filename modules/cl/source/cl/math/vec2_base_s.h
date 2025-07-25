#pragma once

#include "vec2/struct_s.h"
#include "vec2/base.h"
#include "vec2/int.h"

// basic
void vec2_abs(vec2_t& out, const vec2_t& v);
vec2_t vec2n_abs(const vec2_t& out);
void vec2m_abs(vec2_t& out);

void vec2_neg(vec2_t& out, const vec2_t& v);
vec2_t vec2n_neg(const vec2_t& out);
void vec2m_neg(vec2_t& out);
