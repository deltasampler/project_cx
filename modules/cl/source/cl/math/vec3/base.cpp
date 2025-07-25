// arithmetic - vector x vector
void vec3_add(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = v0.x + v1.x;
    out.y = v0.y + v1.y;
    out.z = v0.z + v1.z;
}

vec3_t vec3n_add(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_add(out, v0, v1);

    return out;
}

void vec3m_add(vec3_t& out, const vec3_t& v) {
    vec3_add(out, out, v);
}

void vec3_sub(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = v0.x - v1.x;
    out.y = v0.y - v1.y;
    out.z = v0.z - v1.z;
}

vec3_t vec3n_sub(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_sub(out, v0, v1);

    return out;
}

void vec3m_sub(vec3_t& out, const vec3_t& v) {
    vec3_sub(out, out, v);
}

void vec3_mul(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = v0.x * v1.x;
    out.y = v0.y * v1.y;
    out.z = v0.z * v1.z;
}

vec3_t vec3n_mul(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_mul(out, v0, v1);

    return out;
}

void vec3m_mul(vec3_t& out, const vec3_t& v) {
    vec3_mul(out, out, v);
}

void vec3_div(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = v0.x / v1.x;
    out.y = v0.y / v1.y;
    out.z = v0.z / v1.z;
}

vec3_t vec3n_div(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_div(out, v0, v1);

    return out;
}

void vec3m_div(vec3_t& out, const vec3_t& v) {
    vec3_div(out, out, v);
}

// arithmetic - vector x scalar
void vec3_adds(vec3_t& out, const vec3_t& v, num_t s) {
    out.x = v.x + s;
    out.y = v.y + s;
    out.z = v.z + s;
}

vec3_t vec3n_adds(const vec3_t& v, num_t s) {
    vec3_t out;

    vec3_adds(out, v, s);

    return out;
}

void vec3m_adds(vec3_t& out, num_t s) {
    vec3_adds(out, out, s);
}

void vec3_subs(vec3_t& out, const vec3_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
}

vec3_t vec3n_subs(const vec3_t& v, num_t s) {
    vec3_t out;

    vec3_subs(out, v, s);

    return out;
}

void vec3m_subs(vec3_t& out, num_t s) {
    vec3_subs(out, out, s);
}

void vec3_muls(vec3_t& out, const vec3_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
}

vec3_t vec3n_muls(const vec3_t& v, num_t s) {
    vec3_t out;

    vec3_muls(out, v, s);

    return out;
}

void vec3m_muls(vec3_t& out, num_t s) {
    vec3_muls(out, out, s);
}

void vec3_divs(vec3_t& out, const vec3_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
}

vec3_t vec3n_divs(const vec3_t& v, num_t s) {
    vec3_t out;

    vec3_divs(out, v, s);

    return out;
}

void vec3m_divs(vec3_t& out, num_t s) {
    vec3_divs(out, out, s);
}

// arithmetic - vector x vector x scalar
void vec3_addmuls(vec3_t& out, const vec3_t& v0, const vec3_t& v1, num_t s) {
    out.x = v0.x + v1.x * s;
    out.y = v0.y + v1.y * s;
    out.z = v0.z + v1.z * s;
}

vec3_t vec3n_addmuls(const vec3_t& v0, const vec3_t& v1, num_t s) {
    vec3_t out;

    vec3_addmuls(out, v0, v1, s);

    return out;
}

void vec3m_addmuls(vec3_t& out, const vec3_t& v, num_t s) {
    vec3_addmuls(out, out, v, s);
}

// bounding
void vec3_min(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = mmin(v0.x, v1.x);
    out.y = mmin(v0.y, v1.y);
    out.z = mmin(v0.z, v1.z);
}

vec3_t vec3n_min(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_min(out, v0, v1);

    return out;
}

void vec3_max(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    out.x = mmax(v0.x, v1.x);
    out.y = mmax(v0.y, v1.y);
    out.z = mmax(v0.z, v1.z);
}

vec3_t vec3n_max(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_max(out, v0, v1);

    return out;
}

void vec3_clamp(vec3_t& out, const vec3_t& v, const vec3_t& min, const vec3_t& max) {
    out.x = mclamp(v.x, min.x, max.x);
    out.y = mclamp(v.y, min.y, max.y);
    out.z = mclamp(v.z, min.z, max.z);
}

vec3_t vec3n_clamp(const vec3_t& v, const vec3_t& min, const vec3_t& max) {
    vec3_t out;

    vec3_clamp(out, v, min, max);

    return out;
}

void vec3m_clamp(vec3_t& out, const vec3_t& min, const vec3_t& max) {
    vec3_clamp(out, out, min, max);
}

// string
void vec3_print(const vec3_t& v) {
    char str[128];

    vec3_str(v, str);

    printf("%s\n", str);
}

// arithmetic - operator overloading - vector x vector
vec3_t operator+(const vec3_t& v0, const vec3_t& v1) {
    return vec3n_add(v0, v1);
}

vec3_t& operator+=(vec3_t& out, const vec3_t& v) {
    vec3m_add(out, v);

    return out;
}

vec3_t operator-(const vec3_t& v0, const vec3_t& v1) {
    return vec3n_sub(v0, v1);
}

vec3_t& operator-=(vec3_t& out, const vec3_t& v) {
    vec3m_sub(out, v);

    return out;
}

vec3_t operator*(const vec3_t& v0, const vec3_t& v1) {
    return vec3n_mul(v0, v1);
}

vec3_t& operator*=(vec3_t& out, const vec3_t& v) {
    vec3m_mul(out, v);

    return out;
}

vec3_t operator/(const vec3_t& v0, const vec3_t& v1) {
    return vec3n_div(v0, v1);
}

vec3_t& operator/=(vec3_t& out, const vec3_t& v) {
    vec3m_div(out, v);

    return out;
}

// arithmetic - operator overloading - vector x scalar
vec3_t operator+(const vec3_t& v, num_t s) {
    return vec3n_adds(v, s);
}

vec3_t& operator+=(vec3_t& out, num_t s) {
    vec3m_adds(out, s);

    return out;
}

vec3_t operator-(const vec3_t& v, num_t s) {
    return vec3n_subs(v, s);
}

vec3_t& operator-=(vec3_t& out, num_t s) {
    vec3m_subs(out, s);

    return out;
}

vec3_t operator*(const vec3_t& v, num_t s) {
    return vec3n_muls(v, s);
}

vec3_t& operator*=(vec3_t& out, num_t s) {
    vec3m_muls(out, s);

    return out;
}

vec3_t operator/(const vec3_t& v, num_t s) {
    return vec3n_divs(v, s);
}

vec3_t& operator/=(vec3_t& out, num_t s) {
    vec3m_divs(out, s);

    return out;
}
