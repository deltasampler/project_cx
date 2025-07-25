// special
num_t mat4_det(const mat4_t& m) {
    num_t a00 = m.e00, a01 = m.e01, a02 = m.e02, a03 = m.e03,
          a10 = m.e10, a11 = m.e11, a12 = m.e12, a13 = m.e13,
          a20 = m.e20, a21 = m.e21, a22 = m.e22, a23 = m.e23,
          a30 = m.e30, a31 = m.e31, a32 = m.e32, a33 = m.e33;

    num_t b0 = a00 * a11 - a01 * a10;
    num_t b1 = a00 * a12 - a02 * a10;
    num_t b2 = a01 * a12 - a02 * a11;
    num_t b3 = a20 * a31 - a21 * a30;
    num_t b4 = a20 * a32 - a22 * a30;
    num_t b5 = a21 * a32 - a22 * a31;
    num_t b6 = a00 * b5 - a01 * b4 + a02 * b3;
    num_t b7 = a10 * b5 - a11 * b4 + a12 * b3;
    num_t b8 = a20 * b2 - a21 * b1 + a22 * b0;
    num_t b9 = a30 * b2 - a31 * b1 + a32 * b0;

    return a13 * b6 - a03 * b7 + a33 * b8 - a23 * b9;
}

num_t mat4_frob(const mat4_t& m) {
    return mhypot(
        m.e00, m.e01, m.e02, m.e03,
        m.e10, m.e11, m.e12, m.e13,
        m.e20, m.e21, m.e22, m.e23,
        m.e30, m.e31, m.e32, m.e33
    );
}

void mat4_transp(mat4_t& out, const mat4_t& m) {
    num_t e00 = m.e00, e01 = m.e01, e02 = m.e02, e03 = m.e03,
          e10 = m.e10, e11 = m.e11, e12 = m.e12, e13 = m.e13,
          e20 = m.e20, e21 = m.e21, e22 = m.e22, e23 = m.e23,
          e30 = m.e30, e31 = m.e31, e32 = m.e32, e33 = m.e33;

    out.e00 = e00;
    out.e01 = e10;
    out.e02 = e20;
    out.e03 = e30;
    out.e10 = e01;
    out.e11 = e11;
    out.e12 = e21;
    out.e13 = e31;
    out.e20 = e02;
    out.e21 = e12;
    out.e22 = e22;
    out.e23 = e32;
    out.e30 = e03;
    out.e31 = e13;
    out.e32 = e23;
    out.e33 = e33;
}

mat4_t mat4n_transp(const mat4_t& m) {
    mat4_t out;

    mat4_transp(out, m);

    return out;
}

void mat4m_transp(mat4_t& out) {
    mat4_transp(out, out);
}

void mat4_adjoint(mat4_t& out, const mat4_t& m) {
    num_t a00 = m.e00, a01 = m.e01, a02 = m.e02, a03 = m.e03,
          a10 = m.e10, a11 = m.e11, a12 = m.e12, a13 = m.e13,
          a20 = m.e20, a21 = m.e21, a22 = m.e22, a23 = m.e23,
          a30 = m.e30, a31 = m.e31, a32 = m.e32, a33 = m.e33;

    num_t b00 = a00 * a11 - a01 * a10;
    num_t b01 = a00 * a12 - a02 * a10;
    num_t b02 = a00 * a13 - a03 * a10;
    num_t b03 = a01 * a12 - a02 * a11;
    num_t b04 = a01 * a13 - a03 * a11;
    num_t b05 = a02 * a13 - a03 * a12;
    num_t b06 = a20 * a31 - a21 * a30;
    num_t b07 = a20 * a32 - a22 * a30;
    num_t b08 = a20 * a33 - a23 * a30;
    num_t b09 = a21 * a32 - a22 * a31;
    num_t b10 = a21 * a33 - a23 * a31;
    num_t b11 = a22 * a33 - a23 * a32;

    out.e00 = a11 * b11 - a12 * b10 + a13 * b09;
    out.e01 = a02 * b10 - a01 * b11 - a03 * b09;
    out.e02 = a31 * b05 - a32 * b04 + a33 * b03;
    out.e03 = a22 * b04 - a21 * b05 - a23 * b03;
    out.e10 = a12 * b08 - a10 * b11 - a13 * b07;
    out.e11 = a00 * b11 - a02 * b08 + a03 * b07;
    out.e12 = a32 * b02 - a30 * b05 - a33 * b01;
    out.e13 = a20 * b05 - a22 * b02 + a23 * b01;
    out.e20 = a10 * b10 - a11 * b08 + a13 * b06;
    out.e21 = a01 * b08 - a00 * b10 - a03 * b06;
    out.e22 = a30 * b04 - a31 * b02 + a33 * b00;
    out.e23 = a21 * b02 - a20 * b04 - a23 * b00;
    out.e30 = a11 * b07 - a10 * b09 - a12 * b06;
    out.e31 = a00 * b09 - a01 * b07 + a02 * b06;
    out.e32 = a31 * b01 - a30 * b03 - a32 * b00;
    out.e33 = a20 * b03 - a21 * b01 + a22 * b00;
}

mat4_t mat4n_adjoint(const mat4_t& m) {
    mat4_t out;

    mat4_adjoint(out, m);

    return out;
}

void mat4m_adjoint(mat4_t& out) {
    mat4_adjoint(out, out);
}

void mat4_inv(mat4_t& out, const mat4_t& m) {
    num_t a00 = m.e00, a01 = m.e01, a02 = m.e02, a03 = m.e03,
          a10 = m.e10, a11 = m.e11, a12 = m.e12, a13 = m.e13,
          a20 = m.e20, a21 = m.e21, a22 = m.e22, a23 = m.e23,
          a30 = m.e30, a31 = m.e31, a32 = m.e32, a33 = m.e33;

    num_t b00 = a00 * a11 - a01 * a10;
    num_t b01 = a00 * a12 - a02 * a10;
    num_t b02 = a00 * a13 - a03 * a10;
    num_t b03 = a01 * a12 - a02 * a11;
    num_t b04 = a01 * a13 - a03 * a11;
    num_t b05 = a02 * a13 - a03 * a12;
    num_t b06 = a20 * a31 - a21 * a30;
    num_t b07 = a20 * a32 - a22 * a30;
    num_t b08 = a20 * a33 - a23 * a30;
    num_t b09 = a21 * a32 - a22 * a31;
    num_t b10 = a21 * a33 - a23 * a31;
    num_t b11 = a22 * a33 - a23 * a32;

    num_t det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

    if (mabs(det) < num_t(EPSILON)) {
        return;
    }

    det = num_t(1.0) / det;

    out.e00 = (a11 * b11 - a12 * b10 + a13 * b09) * det;
    out.e01 = (a02 * b10 - a01 * b11 - a03 * b09) * det;
    out.e02 = (a31 * b05 - a32 * b04 + a33 * b03) * det;
    out.e03 = (a22 * b04 - a21 * b05 - a23 * b03) * det;
    out.e10 = (a12 * b08 - a10 * b11 - a13 * b07) * det;
    out.e11 = (a00 * b11 - a02 * b08 + a03 * b07) * det;
    out.e12 = (a32 * b02 - a30 * b05 - a33 * b01) * det;
    out.e13 = (a20 * b05 - a22 * b02 + a23 * b01) * det;
    out.e20 = (a10 * b10 - a11 * b08 + a13 * b06) * det;
    out.e21 = (a01 * b08 - a00 * b10 - a03 * b06) * det;
    out.e22 = (a30 * b04 - a31 * b02 + a33 * b00) * det;
    out.e23 = (a21 * b02 - a20 * b04 - a23 * b00) * det;
    out.e30 = (a11 * b07 - a10 * b09 - a12 * b06) * det;
    out.e31 = (a00 * b09 - a01 * b07 + a02 * b06) * det;
    out.e32 = (a31 * b01 - a30 * b03 - a32 * b00) * det;
    out.e33 = (a20 * b03 - a21 * b01 + a22 * b00) * det;
}

mat4_t mat4n_inv(const mat4_t& m) {
    mat4_t out;

    mat4_inv(out, m);

    return out;
}

void mat4m_inv(mat4_t& out) {
    mat4_inv(out, out);
}

// comparison
bool mat4_equals(const mat4_t& v0, const mat4_t& v1, num_t e) { 
    return mabs(v0.e00 - v1.e00) < e && mabs(v0.e01 - v1.e01) < e && mabs(v0.e02 - v1.e02) < e && mabs(v0.e03 - v1.e03) < e &&
           mabs(v0.e10 - v1.e10) < e && mabs(v0.e11 - v1.e11) < e && mabs(v0.e12 - v1.e12) < e && mabs(v0.e13 - v1.e13) < e &&
           mabs(v0.e20 - v1.e20) < e && mabs(v0.e21 - v1.e21) < e && mabs(v0.e22 - v1.e22) < e && mabs(v0.e23 - v1.e23) < e &&
           mabs(v0.e30 - v1.e30) < e && mabs(v0.e31 - v1.e31) < e && mabs(v0.e32 - v1.e32) < e && mabs(v0.e33 - v1.e33) < e;
}

// string
void mat4_str(const mat4_t& m, char* str) {
    sprintf(
        str,
        "mat4(\n\t%f, %f, %f, %f,\n\t%f, %f, %f, %f,\n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n)",
        m.e00, m.e10, m.e20, m.e30,
        m.e01, m.e11, m.e21, m.e31,
        m.e02, m.e12, m.e22, m.e32,
        m.e03, m.e13, m.e23, m.e33
    );
}
