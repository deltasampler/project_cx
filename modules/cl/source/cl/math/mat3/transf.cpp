// affine
void mat3_translation(mat3_t& out, const vec2_t& v) {
    out.e00 = num_t(1.0);
    out.e01 = num_t(0.0);
    out.e02 = num_t(0.0);
    out.e10 = num_t(0.0);
    out.e11 = num_t(1.0);
    out.e12 = num_t(0.0);
    out.e20 = v.x;
    out.e21 = v.y;
    out.e22 = num_t(1.0);
}

mat3_t mat3n_translation(const vec2_t& v) {
    mat3_t out;

    mat3_translation(out, v);

    return out;
}

void mat3_rotation(mat3_t& out, num_t r) {
    num_t s = msin(r), c = mcos(r);

    out.e00 = c;
    out.e01 = s;
    out.e02 = num_t(0.0);
    out.e10 = -s;
    out.e11 = c;
    out.e12 = num_t(0.0);
    out.e20 = num_t(0.0);
    out.e21 = num_t(0.0);
    out.e22 = num_t(1.0);
}

mat3_t mat3n_rotation(num_t r) {
    mat3_t out;

    mat3_rotation(out, r);

    return out;
}

void mat3_scaling(mat3_t& out, const vec2_t& v) {
    out.e00 = v.x;
    out.e01 = num_t(0.0);
    out.e02 = num_t(0.0);
    out.e10 = num_t(0.0);
    out.e11 = v.y;
    out.e12 = num_t(0.0);
    out.e20 = num_t(0.0);
    out.e21 = num_t(0.0);
    out.e22 = num_t(1.0);
}

mat3_t mat3n_scaling(const vec2_t& v) {
    mat3_t out;

    mat3_scaling(out, v);

    return out;
}

void mat3_translate(mat3_t& out, const mat3_t& m, const vec2_t& v) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02,
          e10 = m.e10, e11 = m.e11, e12 = m.e12,
          e20 = m.e20, e21 = m.e21, e22 = m.e22;
    num_t x = v.x, y = v.y;

    out.e00 = e00;
    out.e01 = e01;
    out.e02 = e02;
    out.e10 = e10;
    out.e11 = e11;
    out.e12 = e12;
    out.e20 = e00 * x + e10 * y + e20;
    out.e21 = e01 * x + e11 * y + e21;
    out.e22 = e02 * x + e12 * y + e22;
}

mat3_t mat3n_translate(const mat3_t& m, const vec2_t& v) {
    mat3_t out;

    mat3_translate(out, m, v);

    return out;
}

void mat3m_translate(mat3_t& out, const vec2_t& v) {
    mat3_translate(out, out, v);
}

void mat3_rotate(mat3_t& out, const mat3_t& m, num_t r) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02,
          e10 = m.e10, e11 = m.e11, e12 = m.e12,
          e20 = m.e20, e21 = m.e21, e22 = m.e22;
    num_t s = msin(r), c = mcos(r);

    out.e00 = e00 * c + e10 * s;
    out.e01 = e01 * c + e11 * s;
    out.e02 = e02 * c + e12 * s;
    out.e10 = e10 * c - e00 * s;
    out.e11 = e11 * c - e01 * s;
    out.e12 = e12 * c - e02 * s;
    out.e20 = e20;
    out.e21 = e21;
    out.e22 = e22;
}

mat3_t mat3n_rotate(const mat3_t& m, num_t r) {
    mat3_t out;

    mat3_rotate(out, m, r);

    return out;
}

void mat3m_rotate(mat3_t& out, num_t r) {
    mat3_rotate(out, out, r);
}

void mat3_scale(mat3_t& out, const mat3_t& m, const vec2_t& v) {
    num_t x = v.x, y = v.y;

    out.e00 = m.e00 * x;
    out.e01 = m.e01 * x;
    out.e02 = m.e02 * x;
    out.e10 = m.e10 * y;
    out.e11 = m.e11 * y;
    out.e12 = m.e12 * y;
    out.e20 = m.e20;
    out.e21 = m.e21;
    out.e22 = m.e22;
}

mat3_t mat3n_scale(const mat3_t& m, const vec2_t& v) {
    mat3_t out;

    mat3_scale(out, m, v);

    return out;
}

void mat3m_scale(mat3_t& out, const vec2_t& v) {
    mat3_scale(out, out, v);
}
