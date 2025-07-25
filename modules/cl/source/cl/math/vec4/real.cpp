// basic
void vec4_abs(vec4_t& out, const vec4_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
    out.z = mabs(v.z);
    out.w = mabs(v.w);
}

vec4_t vec4n_abs(const vec4_t& v) {
    vec4_t out;

    vec4_abs(out, v);

    return out;
}

void vec4m_abs(vec4_t& out) {
    vec4_abs(out, out);
}

void vec4_neg(vec4_t& out, const vec4_t& v) {
    out.x = -v.x;
    out.y = -v.y;
    out.z = -v.z;
    out.w = -v.w;
}

vec4_t vec4n_neg(const vec4_t& v) {
    vec4_t out;

    vec4_neg(out, v);

    return out;
}

void vec4m_neg(vec4_t& out) {
    vec4_neg(out, out);
}

void vec4_inv(vec4_t& out, const vec4_t& v) {
    out.x = num_t(1.0) / v.x;
    out.y = num_t(1.0) / v.y;
    out.z = num_t(1.0) / v.z;
    out.w = num_t(1.0) / v.w;
}

vec4_t vec4n_inv(const vec4_t& v) {
    vec4_t out;

    vec4_inv(out, v);

    return out;
}

void vec4m_inv(vec4_t& out) {
    vec4_inv(out, out);
}

// product
num_t vec4_dot(const vec4_t& v0, const vec4_t& v1) {
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

// norm
num_t vec4_len(const vec4_t& v) {
    return mhypot(v.x, v.y, v.z, v.w);
}

num_t vec4_len_sq(const vec4_t& v) {
    num_t x = v.x, y = v.y, z = v.z, w = v.w;

    return x * x + y * y + z * z + w * w;
}

num_t vec4_dist(const vec4_t& v0, const vec4_t& v1) {
    return mhypot(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w);
}

num_t vec4_dist_sq(const vec4_t& v0, const vec4_t& v1) {
    num_t x = v0.x - v1.x;
    num_t y = v0.y - v1.y;
    num_t z = v0.z - v1.z;
    num_t w = v0.w - v1.w;

    return x * x + y * y + z * z + w * w;
}

void vec4_unit(vec4_t& out, const vec4_t& v) {
    num_t x = v.x, y = v.y, z = v.z, w = v.w;
    num_t l = x * x + y * y + z * z + w * w;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
    out.z = z * l;
    out.w = w * l;
}

vec4_t vec4n_unit(const vec4_t& v) {
    vec4_t out;

    vec4_unit(out, v);

    return out;
}

void vec4m_unit(vec4_t& out) {
    vec4_unit(out, out);
}

void vec4_dir(vec4_t& out, const vec4_t& v0, const vec4_t& v1) {
    num_t x = v0.x - v1.x, y = v0.y - v1.y, z = v0.z - v1.z, w = v0.w - v1.w;
    num_t l = x * x + y * y + z * z + w * w;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
    out.z = z * l;
    out.w = w * l;
}

vec4_t vec4n_dir(vec4_t& v0, const vec4_t& v1) {
    vec4_t out;

    vec4_dir(out, v0, v1);

    return out;
}

// interpolation
void vec4_lerp(vec4_t& out, const vec4_t& v0, const vec4_t& v1, num_t t) {
    num_t x = v0.x, y = v0.y, z = v0.z, w = v0.w;

    out.x = x + t * (v1.x - x);
    out.y = y + t * (v1.y - y);
    out.z = z + t * (v1.z - z);
    out.w = w + t * (v1.w - w);
}

vec4_t vec4n_lerp(const vec4_t& v0, const vec4_t& v1, num_t t) {
    vec4_t out;

    vec4_lerp(out, v0, v1, t);

    return out;
}

void vec4m_lerp(vec4_t& out, const vec4_t& v, num_t t) {
    vec4_lerp(out, out, v, t);
}

// geometric
void vec4_refl(vec4_t& out, const vec4_t& v, const vec4_t& n) {
    num_t l = vec4_dot(n, v) * num_t(2.0);

    out.x = v.x - n.x * l;
    out.y = v.y - n.y * l;
    out.z = v.z - n.z * l;
    out.w = v.w - n.w * l;
}

vec4_t vec4n_refl(const vec4_t& v, const vec4_t& n) {
    vec4_t out;

    vec4_refl(out, v, n);

    return out;
}

// rounding
void vec4_trunc(vec4_t& out, const vec4_t& v) {
    out.x = mtrunc(v.x);
    out.y = mtrunc(v.y);
    out.z = mtrunc(v.z);
    out.w = mtrunc(v.w);
}

vec4_t vec4n_trunc(const vec4_t& v) {
    vec4_t out;

    vec4_trunc(out, v);

    return out;
}

void vec4m_trunc(vec4_t& out) {
    vec4_trunc(out, out);
}

void vec4_floor(vec4_t& out, const vec4_t& v) {
    out.x = mfloor(v.x);
    out.y = mfloor(v.y);
    out.z = mfloor(v.z);
    out.w = mfloor(v.w);
}

vec4_t vec4n_floor(const vec4_t& v) {
    vec4_t out;

    vec4_floor(out, v);

    return out;
}

void vec4m_floor(vec4_t& out) {
    vec4_floor(out, out);
}

void vec4_ceil(vec4_t& out, const vec4_t& v) {
    out.x = mceil(v.x);
    out.y = mceil(v.y);
    out.z = mceil(v.z);
    out.w = mceil(v.w);
}

vec4_t vec4n_ceil(const vec4_t& v) {
    vec4_t out;

    vec4_ceil(out, v);

    return out;
}

void vec4m_ceil(vec4_t& out) {
    vec4_ceil(out, out);
}

void vec4_round(vec4_t& out, const vec4_t& v) {
    out.x = mround(v.x);
    out.y = mround(v.y);
    out.z = mround(v.z);
    out.w = mround(v.w);
}

vec4_t vec4n_round(const vec4_t& v) {
    vec4_t out;

    vec4_round(out, v);

    return out;
}

void vec4m_round(vec4_t& out) {
    vec4_round(out, out);
}

void vec4_snap(vec4_t& out, const vec4_t& v, const vec4_t c) {
    out.x = msnap(v.x, c.x);
    out.y = msnap(v.y, c.y);
    out.z = msnap(v.z, c.z);
    out.w = msnap(v.w, c.w);
}

vec4_t vec4n_snap(const vec4_t& v, const vec4_t c) {
    vec4_t out;

    vec4_snap(out, v, c);

    return out;
}

void vec4m_snap(vec4_t& out, const vec4_t c) {
    vec4_snap(out, out, c);
}

// comparison
bool vec4_equals(const vec4_t& v0, const vec4_t& v1, num_t e) {
    return mabs(v0.x - v1.x) < e && mabs(v0.y - v1.y) < e && mabs(v0.z - v1.z) < e && mabs(v0.w - v1.w) < e;
}

// string
void vec4_str(const vec4_t& v, char* str) {
    sprintf(str, "vec4(%f, %f, %f, %f)", num_t(v.x), num_t(v.y), num_t(v.z), num_t(v.w));
}
