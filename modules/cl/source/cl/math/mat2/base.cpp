// arithmetic - matrix x matrix
void mat2_add(mat2_t& out, const mat2_t& m0, const mat2_t& m1) {
    out.e00 = m0.e00 + m1.e00;
    out.e01 = m0.e01 + m1.e01;
    out.e10 = m0.e10 + m1.e10;
    out.e11 = m0.e11 + m1.e11;
}

mat2_t mat2n_add(const mat2_t& m0, const mat2_t& m1) {
    mat2_t out;

    mat2_add(out, m0, m1);

    return out;
}

void mat2m_add(mat2_t& out, const mat2_t& m) {
    mat2_add(out, out, m);
}

void mat2_sub(mat2_t& out, const mat2_t& m0, const mat2_t& m1) {
    out.e00 = m0.e00 - m1.e00;
    out.e01 = m0.e01 - m1.e01;
    out.e10 = m0.e10 - m1.e10;
    out.e11 = m0.e11 - m1.e11;
}

mat2_t mat2n_sub(const mat2_t& m0, const mat2_t& m1) {
    mat2_t out;

    mat2_sub(out, m0, m1);

    return out;
}

void mat2m_sub(mat2_t& out, const mat2_t& m) {
    mat2_sub(out, out, m);
}

// arithmetic - matrix x scalar
void mat2_muls(mat2_t& out, const mat2_t& m, num_t s) {
    out.e00 = m.e00 * s;
    out.e01 = m.e01 * s;
    out.e10 = m.e10 * s;
    out.e11 = m.e11 * s;
}

mat2_t mat2n_muls(const mat2_t& m, num_t s) {
    mat2_t out;

    mat2_muls(out, m, s);

    return out;
}

void mat2m_muls(mat2_t& out, num_t s) {
    mat2_muls(out, out, s);
}

// arithmetic - matrix x matrix x scalar
void mat2_addmuls(mat2_t& out, const mat2_t& m0, const mat2_t& m1, num_t s) {
    out.e00 = m0.e00 + m1.e00 * s;
    out.e01 = m0.e01 + m1.e01 * s;
    out.e10 = m0.e10 + m1.e10 * s;
    out.e11 = m0.e11 + m1.e11 * s;
}

mat2_t mat2n_addmuls(const mat2_t& m0, const mat2_t& m1, num_t s) {
    mat2_t out;

    mat2_addmuls(out, m0, m1, s);

    return out;
}

void mat2m_addmuls(mat2_t& out, const mat2_t& m, num_t s) {
    mat2_addmuls(out, out, m, s);
}

// product - matrix x matrix
void mat2_mul(mat2_t& out, const mat2_t& m0, const mat2_t& m1) {
    num_t a00 = m0.e00, a01 = m0.e01,
          a10 = m0.e10, a11 = m0.e11;
    num_t b00 = m1.e00, b01 = m1.e01,
          b10 = m1.e10, b11 = m1.e11;

    out.e00 = a00 * b00 + a10 * b01;
    out.e01 = a01 * b00 + a11 * b01;
    out.e10 = a00 * b10 + a10 * b11;
    out.e11 = a01 * b10 + a11 * b11;
}

mat2_t mat2n_mul(const mat2_t& m0, const mat2_t& m1) {
    mat2_t out;

    mat2_mul(out, m0, m1);

    return out;
}

void mat2m_mul(mat2_t& out, const mat2_t& m) {
    mat2_mul(out, out, m);
}

// product - matrix x vector
void mat2_mulmv(vec2_t& out, const vec2_t& v, const mat2_t& m) {
    num_t x = v.x, y = v.y;

    out.x = x * m.e00 + y * m.e10;
    out.y = x * m.e01 + y * m.e11;
}

vec2_t mat2n_mulmv(const vec2_t& v, const mat2_t& m) {
    vec2_t out;

    mat2_mulmv(out, v, m);

    return out;
}

void mat2m_mulmv(vec2_t& out, const mat2_t& m) {
    mat2_mulmv(out, out, m);
}

void mat2_mulvm(vec2_t& out, const vec2_t& v, const mat2_t& m) {
    num_t x = v.x, y = v.y;

    out.x = x * m.e00 + y * m.e01;
    out.y = x * m.e10 + y * m.e11;
}

vec2_t mat2n_mulvm(const vec2_t& v, const mat2_t& m) {
    vec2_t out;

    mat2_mulvm(out, v, m);

    return out;
}

void mat2m_mulvm(vec2_t& out, const mat2_t& m) {
    mat2_mulvm(out, out, m);
}

// string
void mat2_print(const mat2_t& m) {
    char str[128];

    mat2_str(m, str);

    printf("%s\n", str);
}

// arithmetic operator overloading - matrix x matrix
mat2_t operator+(const mat2_t& m0, const mat2_t& m1) {
    return mat2n_add(m0, m1);
}

mat2_t& operator+=(mat2_t& out, const mat2_t& m) {
    mat2m_add(out, m);

    return out;
}

mat2_t operator-(const mat2_t& m0, const mat2_t& m1) {
    return mat2n_sub(m0, m1);
}

mat2_t& operator-=(mat2_t& out, const mat2_t& m) {
    mat2m_sub(out, m);

    return out;
}

// arithmetic operator overloading - matrix x scalar
mat2_t operator*(const mat2_t& m, num_t s) {
    return mat2n_muls(m, s);
}

mat2_t& operator*=(mat2_t& out, num_t s) {
    mat2m_muls(out, s);

    return out;
}

// product operator overloading - matrix x matrix
mat2_t operator*(const mat2_t& m0, const mat2_t& m1) {
    return mat2n_mul(m0, m1);
}

mat2_t& operator*=(mat2_t& out, const mat2_t& m) {
    mat2m_mul(out, m);

    return out;
}

// product operator overloading - matrix x vector
vec2_t operator*(const mat2_t& m, const vec2_t& v) {
    return mat2n_mulmv(v, m);
}

vec2_t operator*(const vec2_t& v, const mat2_t& m) {
    return mat2n_mulvm(v, m);
}

vec2_t& operator*=(vec2_t& out, const mat2_t& m) {
    mat2m_mulvm(out, m);

    return out;
}
