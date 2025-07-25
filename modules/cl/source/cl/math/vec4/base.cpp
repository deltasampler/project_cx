// arithmetic - vector x vector
void vec4_add(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = v0.x + v1.x;
    out.y = v0.y + v1.y;
    out.z = v0.z + v1.z;
    out.w = v0.w + v1.w;
}

vec4_t vec4n_add(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_add(out, v0, v1);

    return out;
}

void vec4m_add(vec4_t& out, const vec4_t& v) {
    vec4_add(out, out, v);
}

void vec4_sub(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = v0.x - v1.x;
    out.y = v0.y - v1.y;
    out.z = v0.z - v1.z;
    out.w = v0.w - v1.w;
}

vec4_t vec4n_sub(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_sub(out, v0, v1);

    return out;
}

void vec4m_sub(vec4_t& out, const vec4_t& v) {
    vec4_sub(out, out, v);
}

void vec4_mul(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = v0.x * v1.x;
    out.y = v0.y * v1.y;
    out.z = v0.z * v1.z;
    out.w = v0.w * v1.w;
}

vec4_t vec4n_mul(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_mul(out, v0, v1);

    return out;
}

void vec4m_mul(vec4_t& out, const vec4_t& v) {
    vec4_mul(out, out, v);
}

void vec4_div(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = v0.x / v1.x;
    out.y = v0.y / v1.y;
    out.z = v0.z / v1.z;
    out.w = v0.w / v1.w;
}

vec4_t vec4n_div(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_div(out, v0, v1);

    return out;
}

void vec4m_div(vec4_t& out, const vec4_t& v) {
    vec4_div(out, out, v);
}

// arithmetic - vector x scalar
void vec4_adds(vec4_t& out, const vec4_t& v, num_t s) {
    out.x = v.x + s;
    out.y = v.y + s;
    out.z = v.z + s;
    out.w = v.w + s;
}

vec4_t vec4n_adds(const vec4_t& v, num_t s) {
    vec4_t out;

    vec4_adds(out, v, s);

    return out;
}

void vec4m_adds(vec4_t& out, num_t s) {
    vec4_adds(out, out, s);
}

void vec4_subs(vec4_t& out, const vec4_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
    out.w = v.w - s;
}

vec4_t vec4n_subs(const vec4_t& v, num_t s) {
    vec4_t out;

    vec4_subs(out, v, s);

    return out;
}

void vec4m_subs(vec4_t& out, num_t s) {
    vec4_subs(out, out, s);
}

void vec4_muls(vec4_t& out, const vec4_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
    out.w = v.w - s;
}

vec4_t vec4n_muls(const vec4_t& v, num_t s) {
    vec4_t out;

    vec4_muls(out, v, s);

    return out;
}

void vec4m_muls(vec4_t& out, num_t s) {
    vec4_muls(out, out, s);
}

void vec4_divs(vec4_t& out, const vec4_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
    out.z = v.z - s;
    out.w = v.w - s;
}

vec4_t vec4n_divs(const vec4_t& v, num_t s) {
    vec4_t out;

    vec4_divs(out, v, s);

    return out;
}

void vec4m_divs(vec4_t& out, num_t s) {
    vec4_divs(out, out, s);
}

// arithmetic - vector x vector x scalar
void vec4_addmuls(vec4_t& out, const vec4_t& v0, const vec4_t& v1, num_t s) {
    out.x = v0.x + v1.x * s;
    out.y = v0.y + v1.y * s;
    out.z = v0.z + v1.z * s;
    out.w = v0.w + v1.w * s;
}

vec4_t vec4n_addmuls(const vec4_t& v0, const vec4_t& v1, num_t s) {
    vec4_t out;

    vec4_addmuls(out, v0, v1, s);

    return out;
}

void vec4m_addmuls(vec4_t& out, const vec4_t& v, num_t s) {
    vec4_addmuls(out, out, v, s);
}

// bounding
void vec4_min(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = mmin(v0.x, v1.x);
    out.y = mmin(v0.y, v1.y);
    out.z = mmin(v0.z, v1.z);
    out.w = mmin(v0.w, v1.w);
}

vec4_t vec4n_min(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_min(out, v0, v1);

    return out;
}

void vec4_max(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    out.x = mmax(v0.x, v1.x);
    out.y = mmax(v0.y, v1.y);
    out.z = mmax(v0.z, v1.z);
    out.w = mmax(v0.w, v1.w);
}

vec4_t vec4n_max(const vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_max(out, v0, v1);

    return out;
}

void vec4_clamp(vec4_t& out, const vec4_t& v, const vec4_t& min, const vec4_t& max) {
    out.x = mclamp(v.x, min.x, max.x);
    out.y = mclamp(v.y, min.y, max.y);
    out.z = mclamp(v.z, min.z, max.z);
    out.w = mclamp(v.w, min.w, max.w);
}

vec4_t vec4n_clamp(const vec4_t& v, const vec4_t& min, const vec4_t& max) {
    vec4_t out;

    vec4_clamp(out, v, min, max);

    return out;
}

void vec4m_clamp(vec4_t& out, const vec4_t& min, const vec4_t& max) {
    vec4_clamp(out, out, min, max);
}

// string
void vec4_print(const vec4_t& v) {
    char str[128];

    vec4_str(v, str);

    printf("%s\n", str);
}

// arithmetic - operator overloading - vector x vector
vec4_t operator+(const vec4_t& v0, const vec4_t& v1) {
    return vec4n_add(v0, v1);
}

vec4_t& operator+=(vec4_t& out, const vec4_t& v) {
    vec4m_add(out, v);

    return out;
}

vec4_t operator-(const vec4_t& v0, const vec4_t& v1) {
    return vec4n_sub(v0, v1);
}

vec4_t& operator-=(vec4_t& out, const vec4_t& v) {
    vec4m_sub(out, v);

    return out;
}

vec4_t operator*(const vec4_t& v0, const vec4_t& v1) {
    return vec4n_mul(v0, v1);
}

vec4_t& operator*=(vec4_t& out, const vec4_t& v) {
    vec4m_mul(out, v);

    return out;
}

vec4_t operator/(const vec4_t& v0, const vec4_t& v1) {
    return vec4n_div(v0, v1);
}

vec4_t& operator/=(vec4_t& out, const vec4_t& v) {
    vec4m_div(out, v);

    return out;
}

// arithmetic - operator overloading - vector x scalar
vec4_t operator+(const vec4_t& v, num_t s) {
    return vec4n_adds(v, s);
}

vec4_t& operator+=(vec4_t& out, num_t s) {
    vec4m_adds(out, s);

    return out;
}

vec4_t operator-(const vec4_t& v, num_t s) {
    return vec4n_subs(v, s);
}

vec4_t& operator-=(vec4_t& out, num_t s) {
    vec4m_subs(out, s);

    return out;
}

vec4_t operator*(const vec4_t& v, num_t s) {
    return vec4n_muls(v, s);
}

vec4_t& operator*=(vec4_t& out, num_t s) {
    vec4m_muls(out, s);

    return out;
}

vec4_t operator/(const vec4_t& v, num_t s) {
    return vec4n_divs(v, s);
}

vec4_t& operator/=(vec4_t& out, num_t s) {
    vec4m_divs(out, s);

    return out;
}
