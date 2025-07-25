// creation
mat2_t pre(mat2)(num_t x) {
    mat2_t out;

    out.e00 = x;
    out.e01 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = x;

    return out;
}

mat2_t pre(mat2)(num_t e00, num_t e01, num_t e10, num_t e11) {
    mat2_t out;

    out.e00 = e00;
    out.e01 = e01;
    out.e10 = e10;
    out.e11 = e11;

    return out;
}

void mat2_zero(mat2_t& out) {
    out.e00 = num_t(0);
    out.e01 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(0);
}

mat2_t pre(mat2n_zero)() {
    mat2_t out;

    mat2_zero(out);

    return out;
}

void mat2_set(mat2_t& out, num_t e00, num_t e01, num_t e10, num_t e11) {
    out.e00 = e00;
    out.e01 = e01;
    out.e10 = e10;
    out.e11 = e11;
}

void mat2_ident(mat2_t& out) {
    out.e00 = num_t(1);
    out.e01 = num_t(0);
    out.e10 = num_t(0);
    out.e11 = num_t(1);
}

mat2_t pre(mat2n_ident)() {
    mat2_t out;

    mat2_ident(out);

    return out;
}

void mat2_copy(mat2_t& out, const mat2_t& m) {
    out.e00 = m.e00;
    out.e01 = m.e01;
    out.e10 = m.e10;
    out.e11 = m.e11;
}

mat2_t mat2n_copy(const mat2_t& m) {
    mat2_t out;

    mat2_copy(out, m);

    return out;
}
