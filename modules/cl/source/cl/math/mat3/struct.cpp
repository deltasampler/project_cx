// creation
mat3_t pre(mat3)(num_t x) {
    mat3_t out;

    out.e00 = x;
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = x;
    out.e12 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = x;

    return out;
}

mat3_t pre(mat3)(num_t e00, num_t e01, num_t e02, num_t e10, num_t e11, num_t e12, num_t e20, num_t e21, num_t e22) {
    mat3_t out;

    out.e00 = e00;
    out.e01 = e01;
    out.e02 = e02;
    out.e10 = e10;
    out.e11 = e11;
    out.e12 = e12;
    out.e20 = e20;
    out.e21 = e21;
    out.e22 = e22;

    return out;
}

void mat3_set(mat3_t& out, num_t e00, num_t e01, num_t e02, num_t e10, num_t e11, num_t e12, num_t e20, num_t e21, num_t e22) {
    out.e00 = e00;
    out.e01 = e01;
    out.e02 = e02;
    out.e10 = e10;
    out.e11 = e11;
    out.e12 = e12;
    out.e20 = e20;
    out.e21 = e21;
    out.e22 = e22;
}

void mat3_zero(mat3_t& out) {
    out.e00 = num_t(0);
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(0);
    out.e12 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = num_t(0);
}

mat3_t pre(mat3n_zero)() {
    mat3_t out;

    mat3_zero(out);

    return out;
}

void mat3_ident(mat3_t& out) {
    out.e00 = num_t(1);
    out.e01 = num_t(0);
    out.e02 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(1);
    out.e12 = num_t(0);
    out.e20 = num_t(0);
    out.e21 = num_t(0);
    out.e22 = num_t(1);
}

mat3_t pre(mat3n_ident)() {
    mat3_t out;

    mat3_ident(out);

    return out;
}

void mat3_copy(mat3_t& out, const mat3_t& m) {
    out.e00 = m.e00;
    out.e01 = m.e01;
    out.e02 = m.e02;
    out.e10 = m.e10;
    out.e11 = m.e11;
    out.e12 = m.e12;
    out.e20 = m.e20;
    out.e21 = m.e21;
    out.e22 = m.e22;
}

mat3_t mat3n_copy(const mat3_t& m) {
    mat3_t out;

    mat3_copy(out, m);

    return out;
}
