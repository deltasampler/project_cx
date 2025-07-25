// special
num_t mat3_det(const mat3_t& m) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02,
          e10 = m.e10, e11 = m.e11, e12 = m.e12,
          e20 = m.e20, e21 = m.e21, e22 = m.e22;

    return (
        e00 * (e22 * e11 - e12 * e21) +
        e01 * (-e22 * e10 + e12 * e20) +
        e02 * (e21 * e10 - e11 * e20)
    );
}

num_t mat3_frob(const mat3_t& m) {
    return mhypot(
        m.e00, m.e01, m.e02,
        m.e10, m.e11, m.e12,
        m.e20, m.e21, m.e22
    );
}

void mat3_transp(mat3_t& out, const mat3_t& m) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02,
          e10 = m.e10, e11 = m.e11, e12 = m.e12,
          e20 = m.e20, e21 = m.e21, e22 = m.e22;

    out.e00 = e00;
    out.e01 = e10;
    out.e02 = e20;
    out.e10 = e01;
    out.e11 = e11;
    out.e12 = e21;
    out.e20 = e02;
    out.e21 = e12;
    out.e22 = e22;
}

mat3_t mat3n_transp(const mat3_t& m) {
    mat3_t out;

    mat3_transp(out, m);

    return out;
}

void mat3m_transp(mat3_t& out) {
    mat3_transp(out, out);
}

void mat3_adjoint(mat3_t& out, const mat3_t& m) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02,
          e10 = m.e10, e11 = m.e11, e12 = m.e12,
          e20 = m.e20, e21 = m.e21, e22 = m.e22;

    out.e00 = e11 * e22 - e12 * e21;
    out.e01 = e02 * e21 - e01 * e22;
    out.e02 = e01 * e12 - e02 * e11;
    out.e10 = e12 * e20 - e10 * e22;
    out.e11 = e00 * e22 - e02 * e20;
    out.e12 = e02 * e10 - e00 * e12;
    out.e20 = e10 * e21 - e11 * e20;
    out.e21 = e01 * e20 - e00 * e21;
    out.e22 = e00 * e11 - e01 * e10;
}

mat3_t mat3n_adjoint(const mat3_t& m) {
    mat3_t out;

    mat3_adjoint(out, m);

    return out;
}

void mat3m_adjoint(mat3_t& out) {
    mat3_adjoint(out, out);
}

void mat3_inv(mat3_t& out, const mat3_t& m) {
    num_t a00 = m.e00, a01 = m.e01, a02 = m.e02,
          a10 = m.e10, a11 = m.e11, a12 = m.e12,
          a20 = m.e20, a21 = m.e21, a22 = m.e22;
    num_t b01 = a22 * a11 - a12 * a21;
    num_t b11 = -a22 * a10 + a12 * a20;
    num_t b21 = a21 * a10 - a11 * a20;
    num_t det = a00 * b01 + a01 * b11 + a02 * b21;

    if (mabs(det) < num_t(EPSILON)) {
        return;
    }

    det = num_t(1.0) / det;

    out.e00 = b01 * det;
    out.e01 = (-a22 * a01 + a02 * a21) * det;
    out.e02 = (a12 * a01 - a02 * a11) * det;
    out.e10 = b11 * det;
    out.e11 = (a22 * a00 - a02 * a20) * det;
    out.e12 = (-a12 * a00 + a02 * a10) * det;
    out.e20 = b21 * det;
    out.e21 = (-a21 * a00 + a01 * a20) * det;
    out.e22 = (a11 * a00 - a01 * a10) * det;
}

mat3_t mat3n_inv(const mat3_t& m) {
    mat3_t out;

    mat3_inv(out, m);

    return out;
}

void mat3m_inv(mat3_t& out) {
    mat3_inv(out, out);
}

// comparison
bool mat3_equals(const mat3_t& v0, const mat3_t& v1, num_t e) {
    return mabs(v0.e00 - v1.e00) < e && mabs(v0.e01 - v1.e01) < e && mabs(v0.e02 - v1.e02) < e &&
           mabs(v0.e10 - v1.e10) < e && mabs(v0.e11 - v1.e11) < e && mabs(v0.e12 - v1.e12) < e &&
           mabs(v0.e20 - v1.e20) < e && mabs(v0.e21 - v1.e21) < e && mabs(v0.e22 - v1.e22) < e;
}

// string
void mat3_str(const mat3_t& m, char* str) {
    sprintf(
        str,
        "mat3(\n\t%f, %f, %f,\n\t%f, %f, %f,\n\t%f, %f, %f\n)\n",
        m.e00, m.e10, m.e20,
        m.e01, m.e11, m.e21,
        m.e02, m.e12, m.e22
    );
}
