// basic
void vec2_abs(vec2_t& out, const vec2_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
}

vec2_t vec2n_abs(const vec2_t& v) {
    vec2_t out;

    vec2_abs(out, v);

    return out;
}

void vec2m_abs(vec2_t& out) {
    vec2_abs(out, out);
}

void vec2_neg(vec2_t& out, const vec2_t& v) {
    out.x = -v.x;
    out.y = -v.y;
}

vec2_t vec2n_neg(const vec2_t& v) {
    vec2_t out;

    vec2_neg(out, v);

    return out;
}

void vec2m_neg(vec2_t& out) {
    vec2_neg(out, out);
}

void vec2_inv(vec2_t& out, const vec2_t& v) {
    out.x = num_t(1.0) / v.x;
    out.y = num_t(1.0) / v.y;
}

vec2_t vec2n_inv(const vec2_t& v) {
    vec2_t out;

    vec2_inv(out, v);

    return out;
}

void vec2m_inv(vec2_t& out) {
    vec2_inv(out, out);
}

// product
num_t vec2_dot(const vec2_t& v0, const vec2_t& v1) {
    return v0.x * v1.x + v0.y * v1.y;
}

num_t vec2_cross(const vec2_t& v0, const vec2_t& v1) {
    return v0.x * v1.y - v0.y * v1.x;
}

// norm
// norm
num_t vec2_len(const vec2_t& v) {
    return mhypot(v.x, v.y);
}

num_t vec2_len_sq(const vec2_t& v) {
    num_t x = v.x, y = v.y;

    return x * x + y * y;
}

num_t vec2_dist(const vec2_t& v0, const vec2_t& v1) {
    return mhypot(v0.x - v1.x, v0.y - v1.y);
}

num_t vec2_dist_sq(const vec2_t& v0, const vec2_t& v1) {
    num_t x = v0.x - v1.x, y = v0.y - v1.y;

    return x * x + y * y;
}

void vec2_unit(vec2_t& out, const vec2_t& v) {
    num_t x = v.x, y = v.y;
    num_t l = x * x + y * y;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
}

vec2_t vec2n_unit(const vec2_t& v) {
    vec2_t out;

    vec2_unit(out, v);

    return out;
}

void vec2m_unit(vec2_t& out) {
    vec2_unit(out, out);
}

void vec2_dir(vec2_t& out, const vec2_t& v0, const vec2_t& v1) {
    num_t x = v0.x - v1.x, y = v0.y - v1.y;
    num_t l = x * x + y * y;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
}

vec2_t vec2n_dir(vec2_t& v0, const vec2_t& v1) {
    vec2_t out;

    vec2_dir(out, v0, v1);

    return out;
}

// interpolation
void vec2_lerp(vec2_t& out, const vec2_t& v0, const vec2_t& v1, num_t t) {
    num_t x = v0.x, y = v0.y;

    out.x = x + t * (v1.x - x);
    out.y = y + t * (v1.y - y);
}

vec2_t vec2n_lerp(const vec2_t& v0, const vec2_t& v1, num_t t) {
    vec2_t out;

    vec2_lerp(out, v0, v1, t);

    return out;
}

void vec2m_lerp(vec2_t& out, const vec2_t& v, num_t t) {
    vec2_lerp(out, out, v, t);
}

// geometric
void vec2_refl(vec2_t& out, const vec2_t& v, const vec2_t& n) {
    num_t l = vec2_dot(n, v) * num_t(2.0);

    out.x = v.x - n.x * l;
    out.y = v.y - n.y * l;
}

vec2_t vec2n_refl(const vec2_t& v, const vec2_t& n) {
    vec2_t out;

    vec2_refl(out, v, n);

    return out;
}

void vec2_perp(vec2_t& out, const vec2_t& v) {
    out.x = -v.y;
    out.y = v.x;
}

vec2_t vec2n_perp(const vec2_t& v) {
    vec2_t out;

    vec2_perp(out, v);

    return out;
}

// rotation
void vec2_rotate(vec2_t& out, const vec2_t& v, num_t r, const vec2_t& p) {
    num_t cx = p.x, cy = p.y;
    num_t x = v.x - cx, y = v.y - cy;
    num_t c = mcos(r), s = msin(r);

    out.x = x * c - y * s + cx;
    out.y = x * s + y * c + cy;
}

vec2_t vec2n_rotate(const vec2_t& v, num_t r, const vec2_t& p) {
    vec2_t out;

    vec2_rotate(out, v, r, p);

    return out;
}

void vec2m_rotate(vec2_t& out, num_t r, const vec2_t& p) {
    vec2_rotate(out, out, r, p);
}

// rounding
void vec2_trunc(vec2_t& out, const vec2_t& v) {
    out.x = mtrunc(v.x);
    out.y = mtrunc(v.y);
}

vec2_t vec2n_trunc(const vec2_t& v) {
    vec2_t out;

    vec2_trunc(out, v);

    return out;
}

void vec2m_trunc(vec2_t& out) {
    vec2_trunc(out, out);
}

void vec2_floor(vec2_t& out, const vec2_t& v) {
    out.x = mfloor(v.x);
    out.y = mfloor(v.y);
}

vec2_t vec2n_floor(const vec2_t& v) {
    vec2_t out;

    vec2_floor(out, v);

    return out;
}

void vec2m_floor(vec2_t& out) {
    vec2_floor(out, out);
}

void vec2_ceil(vec2_t& out, const vec2_t& v) {
    out.x = mceil(v.x);
    out.y = mceil(v.y);
}

vec2_t vec2n_ceil(const vec2_t& v) {
    vec2_t out;

    vec2_ceil(out, v);

    return out;
}

void vec2m_ceil(vec2_t& out) {
    vec2_ceil(out, out);
}

void vec2_round(vec2_t& out, const vec2_t& v) {
    out.x = mround(v.x);
    out.y = mround(v.y);
}

vec2_t vec2n_round(const vec2_t& v) {
    vec2_t out;

    vec2_round(out, v);

    return out;
}

void vec2m_round(vec2_t& out) {
    vec2_round(out, out);
}

void vec2_snap(vec2_t& out, const vec2_t& v, const vec2_t c) {
    out.x = msnap(v.x, c.x);
    out.y = msnap(v.y, c.y);
}

vec2_t vec2n_snap(const vec2_t& v, const vec2_t c) {
    vec2_t out;

    vec2_snap(out, v, c);

    return out;
}

void vec2m_snap(vec2_t& out, const vec2_t c) {
    vec2_snap(out, out, c);
}

// comparison
bool vec2_equals(const vec2_t& v0, const vec2_t& v1, num_t e) {
    return mabs(v0.x - v1.x) < e && mabs(v0.y - v1.y) < e;
}

// string
void vec2_str(const vec2_t& v, char* str) {
    sprintf(str, "vec2(%f, %f)", num_t(v.x), num_t(v.y));
}
