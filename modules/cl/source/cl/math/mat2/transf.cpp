// affine
void mat2_rotation(mat2_t& out, num_t r) {
    num_t s = msin(r), c = mcos(r);

    out.e00 = c;
    out.e01 = s;
    out.e10 = -s;
    out.e11 = c;
}

mat2_t mat2n_rotation(num_t r) {
    mat2_t out;

    mat2_rotation(out, r);

    return out;
}

void mat2_scaling(mat2_t& out, const vec2_t& v) {
    out.e00 = v.x;
    out.e01 = num_t(0.0);
    out.e10 = num_t(0.0);
    out.e10 = v.y;
}

mat2_t mat2n_scaling(const vec2_t& v) {
    mat2_t out;

    mat2_scaling(out, v);

    return out;
}

void mat2_rotate(mat2_t& out, const mat2_t& m, num_t r) {
    num_t e00 = m.e00, e01 = m.e01,
          e10 = m.e10, e11 = m.e11;
    num_t s = msin(r), c = mcos(r);

    out.e00 = e00 * c + e10 * s;
    out.e01 = e01 * c + e11 * s;
    out.e10 = e00 * -s + e10 * c;
    out.e11 = e01 * -s + e11 * c;
}

mat2_t mat2n_rotate(const mat2_t& m, num_t r) {
    mat2_t out;

    mat2_rotate(out, m, r);

    return out;
}

void mat2m_rotate(mat2_t& out, num_t r) {
    mat2_rotate(out, out, r);
}

void mat2_scale(mat2_t& out, const mat2_t& m, const vec2_t& v) {
    num_t x = v.x, y = v.y;

    out.e00 = m.e00 * x;
    out.e01 = m.e01 * x;
    out.e10 = m.e10 * y;
    out.e11 = m.e11 * y;
}

mat2_t mat2n_scale(const mat2_t& m, const vec2_t& v) {
    mat2_t out;

    mat2_scale(out, m, v);

    return out;
}

void mat2m_scale(mat2_t& out, const vec2_t& v) {
    mat2_scale(out, out, v);
}
