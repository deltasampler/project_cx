// special
num_t mat2_det(const mat2_t& m) {
    return m.e00 * m.e11 - m.e10 * m.e01;
}

num_t mat2_frob(const mat2_t& m) {
    return mhypot(
        m.e00, m.e01,
        m.e10, m.e11
    );
}

void mat2_transp(mat2_t& out, const mat2_t& m) {
    num_t temp = m.e01;

    out.e00 = m.e00;
    out.e01 = m.e10;
    out.e10 = temp;
    out.e11 = m.e11;
}

mat2_t mat2n_transp(const mat2_t& m) {
    mat2_t out;

    mat2_transp(out, m);

    return out;
}

void mat2m_transp(mat2_t& out) {
    mat2_transp(out, out);
}

void mat2_adjoint(mat2_t& out, const mat2_t& m) {
    out.e00 = m.e11;
    out.e01 = -m.e01;
    out.e10 = -m.e10;
    out.e11 = m.e00;
}

mat2_t mat2n_adjoint(const mat2_t& m) {
    mat2_t out;

    mat2_adjoint(out, m);

    return out;
}

void mat2m_adjoint(mat2_t& out) {
    mat2_adjoint(out, out);
}

void mat2_inv(mat2_t& out, const mat2_t& m) {
    num_t e00 = m.e00, e01 = m.e01,
          e10 = m.e10, e11 = m.e11;
    num_t det = e00 * e11 - e10 * e01;

    if (mabs(det) < num_t(EPSILON)) {
        return;
    }

    det = num_t(1.0) / det;

    out.e00 = e11 * det;
    out.e01 = -e01 * det;
    out.e10 = -e10 * det;
    out.e11 = e00 * det;
}

mat2_t mat2n_inv(const mat2_t& m) {
    mat2_t out;

    mat2_inv(out, m);

    return out;
}

void mat2m_inv(mat2_t& out) {
    mat2_inv(out, out);
}

// comparison
bool mat2_equals(const mat2_t& v0, const mat2_t& v1, num_t e) {
    return mabs(v0.e00 - v1.e00) < e && mabs(v0.e01 - v1.e01) < e &&
           mabs(v0.e10 - v1.e10) < e && mabs(v0.e11 - v1.e11) < e;
}

// string
void mat2_str(const mat2_t& m, char* str) {
    sprintf(
        str,
        "mat2(\n\t%f, %f,\n\t%f, %f\n)",
        m.e00, m.e10,
        m.e01, m.e11
    );
}
