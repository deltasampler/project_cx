// arithmetic - vector x vector
void vec2_add(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = v0.x + v1.x;
    out.y = v0.y + v1.y;
}

vec2_t vec2n_add(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_add(out, v0, v1);

    return out;
}

void vec2m_add(vec2_t& out, const vec2_t& v) {
    vec2_add(out, out, v);
}

void vec2_sub(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = v0.x - v1.x;
    out.y = v0.y - v1.y;
}

vec2_t vec2n_sub(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_sub(out, v0, v1);

    return out;
}

void vec2m_sub(vec2_t& out, const vec2_t& v) {
    vec2_sub(out, out, v);
}

void vec2_mul(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = v0.x * v1.x;
    out.y = v0.y * v1.y;
}

vec2_t vec2n_mul(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_mul(out, v0, v1);

    return out;
}

void vec2m_mul(vec2_t& out, const vec2_t& v) {
    vec2_mul(out, out, v);
}

void vec2_div(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = v0.x / v1.x;
    out.y = v0.y / v1.y;
}

vec2_t vec2n_div(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_div(out, v0, v1);

    return out;
}

void vec2m_div(vec2_t& out, const vec2_t& v) {
    vec2_div(out, out, v);
}

// arithmetic - vector x scalar
void vec2_adds(vec2_t& out, const vec2_t& v, num_t s) {
    out.x = v.x + s;
    out.y = v.y + s;
}

vec2_t vec2n_adds(const vec2_t& v, num_t s) {
    vec2_t out;

    vec2_adds(out, v, s);

    return out;
}

void vec2m_adds(vec2_t& out, num_t s) {
    vec2_adds(out, out, s);
}

void vec2_subs(vec2_t& out, const vec2_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
}

vec2_t vec2n_subs(const vec2_t& v, num_t s) {
    vec2_t out;

    vec2_subs(out, v, s);

    return out;
}

void vec2m_subs(vec2_t& out, num_t s) {
    vec2_subs(out, out, s);
}

void vec2_muls(vec2_t& out, const vec2_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
}

vec2_t vec2n_muls(const vec2_t& v, num_t s) {
    vec2_t out;

    vec2_muls(out, v, s);

    return out;
}

void vec2m_muls(vec2_t& out, num_t s) {
    vec2_muls(out, out, s);
}

void vec2_divs(vec2_t& out, const vec2_t& v, num_t s) {
    out.x = v.x - s;
    out.y = v.y - s;
}

vec2_t vec2n_divs(const vec2_t& v, num_t s) {
    vec2_t out;

    vec2_divs(out, v, s);

    return out;
}

void vec2m_divs(vec2_t& out, num_t s) {
    vec2_divs(out, out, s);
}

// arithmetic - vector x vector x scalar
void vec2_addmuls(vec2_t& out, const vec2_t& v0, const vec2_t& v1, num_t s) {
    out.x = v0.x + v1.x * s;
    out.y = v0.y + v1.y * s;
}

vec2_t vec2n_addmuls(const vec2_t& v0, const vec2_t& v1, num_t s) {
    vec2_t out;

    vec2_addmuls(out, v0, v1, s);

    return out;
}

void vec2m_addmuls(vec2_t& out, const vec2_t& v, num_t s) {
    vec2_addmuls(out, out, v, s);
}

// bounding
void vec2_min(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = mmin(v0.x, v1.x);
    out.y = mmin(v0.y, v1.y);
}

vec2_t vec2n_min(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_min(out, v0, v1);

    return out;
}

void vec2_max(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    out.x = mmax(v0.x, v1.x);
    out.y = mmax(v0.y, v1.y);
}

vec2_t vec2n_max(const vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_max(out, v0, v1);

    return out;
}

void vec2_clamp(vec2_t& out, const vec2_t& v, const vec2_t& min, const vec2_t& max) {
    out.x = mclamp(v.x, min.x, max.x);
    out.y = mclamp(v.y, min.y, max.y);
}

vec2_t vec2n_clamp(const vec2_t& v, const vec2_t& min, const vec2_t& max) {
    vec2_t out;

    vec2_clamp(out, v, min, max);

    return out;
}

void vec2m_clamp(vec2_t& out, const vec2_t& min, const vec2_t& max) {
    vec2_clamp(out, out, min, max);
}

// string
void vec2_print(const vec2_t& v) {
    char str[128];

    vec2_str(v, str);

    printf("%s\n", str);
}

// arithmetic - operator overloading - vector x vector
vec2_t operator+(const vec2_t& v0, const vec2_t& v1) {
    return vec2n_add(v0, v1);
}

vec2_t& operator+=(vec2_t& out, const vec2_t& v) {
    vec2m_add(out, v);

    return out;
}

vec2_t operator-(const vec2_t& v0, const vec2_t& v1) {
    return vec2n_sub(v0, v1);
}

vec2_t& operator-=(vec2_t& out, const vec2_t& v) {
    vec2m_sub(out, v);

    return out;
}

vec2_t operator*(const vec2_t& v0, const vec2_t& v1) {
    return vec2n_mul(v0, v1);
}

vec2_t& operator*=(vec2_t& out, const vec2_t& v) {
    vec2m_mul(out, v);

    return out;
}

vec2_t operator/(const vec2_t& v0, const vec2_t& v1) {
    return vec2n_div(v0, v1);
}

vec2_t& operator/=(vec2_t& out, const vec2_t& v) {
    vec2m_div(out, v);

    return out;
}

// arithmetic - operator overloading - vector x scalar
vec2_t operator+(const vec2_t& v, num_t s) {
    return vec2n_adds(v, s);
}

vec2_t& operator+=(vec2_t& out, num_t s) {
    vec2m_adds(out, s);

    return out;
}

vec2_t operator-(const vec2_t& v, num_t s) {
    return vec2n_subs(v, s);
}

vec2_t& operator-=(vec2_t& out, num_t s) {
    vec2m_subs(out, s);

    return out;
}

vec2_t operator*(const vec2_t& v, num_t s) {
    return vec2n_muls(v, s);
}

vec2_t& operator*=(vec2_t& out, num_t s) {
    vec2m_muls(out, s);

    return out;
}

vec2_t operator/(const vec2_t& v, num_t s) {
    return vec2n_divs(v, s);
}

vec2_t& operator/=(vec2_t& out, num_t s) {
    vec2m_divs(out, s);

    return out;
}
