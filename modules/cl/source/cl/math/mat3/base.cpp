// arithmetic - matrix x matrix
void mat3_add(mat3_t& out, const mat3_t& m0, const mat3_t& m1) {
    out.e00 = m0.e00 + m1.e00;
    out.e01 = m0.e01 + m1.e01;
    out.e02 = m0.e02 + m1.e02;
    out.e10 = m0.e10 + m1.e10;
    out.e11 = m0.e11 + m1.e11;
    out.e12 = m0.e12 + m1.e12;
    out.e20 = m0.e20 + m1.e20;
    out.e21 = m0.e21 + m1.e21;
    out.e22 = m0.e22 + m1.e22;
}

mat3_t mat3n_add(const mat3_t& m0, const mat3_t& m1) {
    mat3_t out;

    mat3_add(out, m0, m1);

    return out;
}

void mat3m_add(mat3_t& out, const mat3_t& m) {
    mat3_add(out, out, m);
}

void mat3_sub(mat3_t& out, const mat3_t& m0, const mat3_t& m1) {
    out.e00 = m0.e00 - m1.e00;
    out.e01 = m0.e01 - m1.e01;
    out.e02 = m0.e02 - m1.e02;
    out.e10 = m0.e10 - m1.e10;
    out.e11 = m0.e11 - m1.e11;
    out.e12 = m0.e12 - m1.e12;
    out.e20 = m0.e20 - m1.e20;
    out.e21 = m0.e21 - m1.e21;
    out.e22 = m0.e22 - m1.e22;
}

mat3_t mat3n_sub(const mat3_t& m0, const mat3_t& m1) {
    mat3_t out;

    mat3_sub(out, m0, m1);

    return out;
}

void mat3m_sub(mat3_t& out, const mat3_t& m) {
    mat3_sub(out, out, m);
}

// arithmetic - matrix x scalar
void mat3_muls(mat3_t& out, const mat3_t& m, num_t s) {
    out.e00 = m.e00 * s;
    out.e01 = m.e01 * s;
    out.e02 = m.e02 * s;
    out.e10 = m.e10 * s;
    out.e11 = m.e11 * s;
    out.e12 = m.e12 * s;
    out.e20 = m.e20 * s;
    out.e21 = m.e21 * s;
    out.e22 = m.e22 * s;
}

mat3_t mat3n_muls(const mat3_t& m, num_t s) {
    mat3_t out;

    mat3_muls(out, m, s);

    return out;
}

void mat3m_muls(mat3_t& out, num_t s) {
    mat3_muls(out, out, s);
}

// arithmetic - matrix x matrix x scalar
void mat3_addmuls(mat3_t& out, const mat3_t& m0, const mat3_t& m1, num_t s) {
    out.e00 = m0.e00 + m1.e00 * s;
    out.e01 = m0.e01 + m1.e01 * s;
    out.e02 = m0.e02 + m1.e02 * s;
    out.e10 = m0.e10 + m1.e10 * s;
    out.e11 = m0.e11 + m1.e11 * s;
    out.e12 = m0.e12 + m1.e12 * s;
    out.e20 = m0.e20 + m1.e20 * s;
    out.e21 = m0.e21 + m1.e21 * s;
    out.e22 = m0.e22 + m1.e22 * s;
}

mat3_t mat3n_addmuls(const mat3_t& m0, const mat3_t& m1, num_t s) {
    mat3_t out;

    mat3_addmuls(out, m0, m1, s);

    return out;
}

void mat3m_addmuls(mat3_t& out, const mat3_t& m, num_t s) {
    mat3_addmuls(out, out, m, s);
}

// product - matrix x matrix
void mat3_mul(mat3_t& out, const mat3_t& m0, const mat3_t& m1) {
    num_t a00 = m0.e00, a01 = m0.e01, a02 = m0.e02,
          a10 = m0.e10, a11 = m0.e11, a12 = m0.e12,
          a20 = m0.e20, a21 = m0.e21, a22 = m0.e22;
    num_t b00 = m1.e00, b01 = m1.e01, b02 = m1.e02,
          b10 = m1.e10, b11 = m1.e11, b12 = m1.e12,
          b20 = m1.e20, b21 = m1.e21, b22 = m1.e22;

    out.e00 = a00 * b00 + a10 * b01 + a20 * b02;
    out.e01 = a01 * b00 + a11 * b01 + a21 * b02;
    out.e02 = a02 * b00 + a12 * b01 + a22 * b02;
    out.e10 = a00 * b10 + a10 * b11 + a20 * b12;
    out.e11 = a01 * b10 + a11 * b11 + a21 * b12;
    out.e12 = a02 * b10 + a12 * b11 + a22 * b12;
    out.e20 = a00 * b20 + a10 * b21 + a20 * b22;
    out.e21 = a01 * b20 + a11 * b21 + a21 * b22;
    out.e22 = a02 * b20 + a12 * b21 + a22 * b22;
}

mat3_t mat3n_mul(const mat3_t& m0, const mat3_t& m1) {
    mat3_t out;

    mat3_mul(out, m0, m1);

    return out;
}

void mat3m_mul(mat3_t& out, const mat3_t& m) {
    mat3_mul(out, out, m);
}

// product - matrix x vector
void mat3_mulmv(vec3_t& out, const vec3_t& v, const mat3_t& m) {
    num_t x = v.x, y = v.y, z = v.z;

    out.x = x * m.e00 + y * m.e10 + z * m.e20;
    out.y = x * m.e01 + y * m.e11 + z * m.e21;
    out.z = x * m.e02 + y * m.e12 + z * m.e22;
}

vec3_t mat3n_mulmv(const vec3_t& v, const mat3_t& m) {
    vec3_t out;

    mat3_mulmv(out, v, m);

    return out;
}

void mat3m_mulmv(vec3_t& out, const mat3_t& m) {
    mat3_mulmv(out, out, m);
}

void mat3_mulvm(vec3_t& out, const vec3_t& v, const mat3_t& m) {
    num_t x = v.x, y = v.y, z = v.z;

    out.x = x * m.e00 + y * m.e01 + z * m.e02;
    out.y = x * m.e10 + y * m.e11 + z * m.e12;
    out.z = x * m.e20 + y * m.e21 + z * m.e22;
}

vec3_t mat3n_mulvm(const vec3_t& v, const mat3_t& m) {
    vec3_t out;

    mat3_mulvm(out, v, m);

    return out;
}

void mat3m_mulvm(vec3_t& out, const mat3_t& m) {
    mat3_mulvm(out, out, m);
}

// string
void mat3_print(const mat3_t& m) {
    char str[128];

    mat3_str(m, str);

    printf("%s\n", str);
}

// arithmetic operator overloading - matrix x matrix
mat3_t operator+(const mat3_t& m0, const mat3_t& m1) {
    return mat3n_add(m0, m1);
}

mat3_t& operator+=(mat3_t& out, const mat3_t& m) {
    mat3m_add(out, m);

    return out;
}

mat3_t operator-(const mat3_t& m0, const mat3_t& m1) {
    return mat3n_sub(m0, m1);
}

mat3_t& operator-=(mat3_t& out, const mat3_t& m) {
    mat3m_sub(out, m);

    return out;
}

// arithmetic operator overloading - matrix x scalar
mat3_t operator*(const mat3_t& m, num_t s) {
    return mat3n_muls(m, s);
}

mat3_t& operator*=(mat3_t& out, num_t s) {
    mat3m_muls(out, s);

    return out;
}

// product operator overloading - matrix x matrix
mat3_t operator*(const mat3_t& m0, const mat3_t& m1) {
    return mat3n_mul(m0, m1);
}

mat3_t& operator*=(mat3_t& out, const mat3_t& m) {
    mat3m_mul(out, m);

    return out;
}

// product operator overloading - matrix x vector
vec3_t operator*(const mat3_t& m, const vec3_t& v) {
    return mat3n_mulmv(v, m);
}

vec3_t operator*(const vec3_t& v, const mat3_t& m) {
    return mat3n_mulvm(v, m);
}

vec3_t& operator*=(vec3_t& out, const mat3_t& m) {
    mat3m_mulvm(out, m);

    return out;
}
