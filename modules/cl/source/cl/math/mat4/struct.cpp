// creation
mat4_t pre(mat4)(num_t x) {
    mat4_t out;

    out.e00 = x;
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e03 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = x;
    out.e12 = num_t(0);
    out.e13 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = x;
    out.e23 = num_t(0);
    out.e30 = num_t(0);
    out.e31 = num_t(0);
    out.e32 = num_t(0);
    out.e33 = x;

    return out;
}

mat4_t pre(mat4)(num_t e00, num_t e01, num_t e02, num_t e03, num_t e10, num_t e11, num_t e12, num_t e13, num_t e20, num_t e21, num_t e22, num_t e23, num_t e30, num_t e31, num_t e32, num_t e33) {
    mat4_t out;

    out.e00 = e00;
    out.e01 = e01;
    out.e02 = e02;
    out.e03 = e03;
    out.e10 = e10;
    out.e11 = e11;
    out.e12 = e12;
    out.e13 = e13;
    out.e20 = e20;
    out.e21 = e21;
    out.e22 = e22;
    out.e23 = e23;
    out.e30 = e30;
    out.e31 = e31;
    out.e32 = e32;
    out.e33 = e33;

    return out;
}

void mat4_set(mat4_t& out, num_t e00, num_t e01, num_t e02, num_t e03, num_t e10, num_t e11, num_t e12, num_t e13, num_t e20, num_t e21, num_t e22, num_t e23, num_t e30, num_t e31, num_t e32, num_t e33) {
    out.e00 = e00;
    out.e01 = e01;
    out.e02 = e02;
    out.e03 = e03;
    out.e10 = e10;
    out.e11 = e11;
    out.e12 = e12;
    out.e13 = e13;
    out.e20 = e20;
    out.e21 = e21;
    out.e22 = e22;
    out.e23 = e23;
    out.e30 = e30;
    out.e31 = e31;
    out.e32 = e32;
    out.e33 = e33;
}

void mat4_zero(mat4_t& out) {
    out.e00 = num_t(0);
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e03 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(0);
    out.e13 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = num_t(0);
    out.e23 = num_t(0);
    out.e30 = num_t(0);
    out.e31 = num_t(0);
    out.e32 = num_t(0);
    out.e33 = num_t(0);
}

mat4_t pre(mat4n_zero)() {
    mat4_t out;

    mat4_zero(out);

    return out;
}

void mat4_ident(mat4_t& out) {
    out.e00 = num_t(1);
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e03 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(1);
    out.e12 = num_t(0);
    out.e13 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = num_t(1);
    out.e23 = num_t(0);
    out.e30 = num_t(0);
    out.e31 = num_t(0);
    out.e32 = num_t(0);
    out.e33 = num_t(1);
}

mat4_t pre(mat4n_ident)() {
    mat4_t out;

    mat4_ident(out);

    return out;
}

void mat4_copy(mat4_t& out, const mat4_t& m) {
    out.e00 = m.e00;
    out.e01 = m.e01;
    out.e02 = m.e02;
    out.e03 = m.e03;
    out.e10 = m.e10;
    out.e11 = m.e11;
    out.e12 = m.e12;
    out.e13 = m.e13;
    out.e20 = m.e20;
    out.e21 = m.e21;
    out.e22 = m.e22;
    out.e23 = m.e23;
    out.e30 = m.e30;
    out.e31 = m.e31;
    out.e32 = m.e32;
    out.e33 = m.e33;
}

mat4_t mat4n_copy(const mat4_t& m) {
    mat4_t out;

    mat4_copy(out, m);

    return out;
}
