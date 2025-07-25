// basic
void vec3_abs(vec3_t& out, const vec3_t& v) {
    out.x = mabs(v.x);
    out.y = mabs(v.y);
    out.z = mabs(v.z);
}

vec3_t vec3n_abs(const vec3_t& v) {
    vec3_t out;

    vec3_abs(out, v);

    return out;
}

void vec3m_abs(vec3_t& out) {
    vec3_abs(out, out);
}

void vec3_neg(vec3_t& out, const vec3_t& v) {
    out.x = -v.x;
    out.y = -v.y;
    out.z = -v.z;
}

vec3_t vec3n_neg(const vec3_t& v) {
    vec3_t out;

    vec3_neg(out, v);

    return out;
}

void vec3m_neg(vec3_t& out) {
    vec3_neg(out, out);
}

void vec3_inv(vec3_t& out, const vec3_t& v) {
    out.x = num_t(1.0) / v.x;
    out.y = num_t(1.0) / v.y;
    out.z = num_t(1.0) / v.z;
}

vec3_t vec3n_inv(const vec3_t& v) {
    vec3_t out;

    vec3_inv(out, v);

    return out;
}

void vec3m_inv(vec3_t& out) {
    vec3_inv(out, out);
}

// product
num_t vec3_dot(const vec3_t& v0, const vec3_t& v1) {
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

void vec3_cross(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    num_t ax = v0.x, ay = v0.y, az = v0.z;
    num_t bx = v1.x, by = v1.y, bz = v1.z;

    out.x = ay * bz - az * by;
    out.y = az * bx - ax * bz;
    out.z = ax * by - ay * bx;
}

vec3_t vec3n_cross(const vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_cross(out, v0, v1);

    return out;
}

// norm
num_t vec3_len(const vec3_t& v) {
    return mhypot(v.x, v.y, v.z);
}

num_t vec3_len_sq(const vec3_t& v) {
    num_t x = v.x, y = v.y, z = v.z;

    return x * x + y * y + z * z;
}

num_t vec3_dist(const vec3_t& v0, const vec3_t& v1) {
    return mhypot(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
}

num_t vec3_dist_sq(const vec3_t& v0, const vec3_t& v1) {
    num_t x = v0.x - v1.x;
    num_t y = v0.y - v1.y;
    num_t z = v0.z - v1.z;

    return x * x + y * y + z * z;
}

void vec3_unit(vec3_t& out, const vec3_t& v) {
    num_t x = v.x, y = v.y, z = v.z;
    num_t l = x * x + y * y + z * z;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
    out.z = z * l;
}

vec3_t vec3n_unit(const vec3_t& v) {
    vec3_t out;

    vec3_unit(out, v);

    return out;
}

void vec3m_unit(vec3_t& out) {
    vec3_unit(out, out);
}

void vec3_dir(vec3_t& out, const vec3_t& v0, const vec3_t& v1) {
    num_t x = v0.x - v1.x, y = v0.y - v1.y, z = v0.z - v1.z;
    num_t l = x * x + y * y + z * z;

    if (l > num_t(0.0)) {
        l = num_t(1.0) / msqrt(l);
    }

    out.x = x * l;
    out.y = y * l;
    out.z = z * l;
}

vec3_t vec3n_dir(vec3_t& v0, const vec3_t& v1) {
    vec3_t out;

    vec3_dir(out, v0, v1);

    return out;
}

// interpolation
void vec3_lerp(vec3_t& out, const vec3_t& v0, const vec3_t& v1, num_t t) {
    num_t x = v0.x, y = v0.y, z = v0.z;

    out.x = x + t * (v1.x - x);
    out.y = y + t * (v1.y - y);
    out.z = z + t * (v1.z - z);
}

vec3_t vec3n_lerp(const vec3_t& v0, const vec3_t& v1, num_t t) {
    vec3_t out;

    vec3_lerp(out, v0, v1, t);

    return out;
}

void vec3m_lerp(vec3_t& out, const vec3_t& v, num_t t) {
    vec3_lerp(out, out, v, t);
}

// geometric
void vec3_refl(vec3_t& out, const vec3_t& v, const vec3_t& n) {
    num_t l = vec3_dot(n, v) * num_t(2.0);

    out.x = v.x - n.x * l;
    out.y = v.y - n.y * l;
    out.z = v.z - n.z * l;
}

vec3_t vec3n_refl(const vec3_t& v, const vec3_t& n) {
    vec3_t out;

    vec3_refl(out, v, n);

    return out;
}

// rotation
void vec3_rotate_x(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p) {
    num_t p0 = v.x - p.x, p1 = v.y - p.y, p2 = v.z - p.z;
    num_t r0 = p0,
          r1 = p1 * mcos(r) - p2 * msin(r),
          r2 = p1 * msin(r) + p2 * mcos(r);

    out.x = r0 + p.x;
    out.y = r1 + p.y;
    out.z = r2 + p.z;
}

vec3_t vec3n_rotate_x(const vec3_t& v, num_t r, const vec3_t& p) {
    vec3_t out;

    vec3_rotate_x(out, v, r, p);

    return out;
}

void vec3m_rotate_x(vec3_t& out, num_t r, const vec3_t& p) {
    vec3_rotate_x(out, out, r, p);
}

void vec3_rotate_y(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p) {
    num_t p0 = v.x - p.x, p1 = v.y - p.y, p2 = v.z - p.z;
    num_t r0 = p2 * msin(r) + p0 * mcos(r),
          r1 = p1,
          r2 = p2 * mcos(r) - p0 * msin(r);

    out.x = r0 + p.x;
    out.y = r1 + p.y;
    out.z = r2 + p.z;
}

vec3_t vec3n_rotate_y(const vec3_t& v, num_t r, const vec3_t& p) {
    vec3_t out;

    vec3_rotate_y(out, v, r, p);

    return out;
}

void vec3m_rotate_y(vec3_t& out, num_t r, const vec3_t& p) {
    vec3_rotate_y(out, out, r, p);
}

void vec3_rotate_z(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p) {
    num_t p0 = v.x - p.x, p1 = v.y - p.y, p2 = v.z - p.z;
    num_t r0 = p0 * mcos(r) - p1 * msin(r),
          r1 = p0 * msin(r) + p1 * mcos(r),
          r2 = p2;

    out.x = r0 + p.x;
    out.y = r1 + p.y;
    out.z = r2 + p.z;
}

vec3_t vec3n_rotate_z(const vec3_t& v, num_t r, const vec3_t& p) {
    vec3_t out;

    vec3_rotate_z(out, v, r, p);

    return out;
}

void vec3m_rotate_z(vec3_t& out, num_t r, const vec3_t& p) {
    vec3_rotate_z(out, out, r, p);
}

// rounding
void vec3_trunc(vec3_t& out, const vec3_t& v) {
    out.x = mtrunc(v.x);
    out.y = mtrunc(v.y);
    out.z = mtrunc(v.z);
}

vec3_t vec3n_trunc(const vec3_t& v) {
    vec3_t out;

    vec3_trunc(out, v);

    return out;
}

void vec3m_trunc(vec3_t& out) {
    vec3_trunc(out, out);
}

void vec3_floor(vec3_t& out, const vec3_t& v) {
    out.x = mfloor(v.x);
    out.y = mfloor(v.y);
    out.z = mfloor(v.z);
}

vec3_t vec3n_floor(const vec3_t& v) {
    vec3_t out;

    vec3_floor(out, v);

    return out;
}

void vec3m_floor(vec3_t& out) {
    vec3_floor(out, out);
}

void vec3_ceil(vec3_t& out, const vec3_t& v) {
    out.x = mceil(v.x);
    out.y = mceil(v.y);
    out.z = mceil(v.z);
}

vec3_t vec3n_ceil(const vec3_t& v) {
    vec3_t out;

    vec3_ceil(out, v);

    return out;
}

void vec3m_ceil(vec3_t& out) {
    vec3_ceil(out, out);
}

void vec3_round(vec3_t& out, const vec3_t& v) {
    out.x = mround(v.x);
    out.y = mround(v.y);
    out.z = mround(v.z);
}

vec3_t vec3n_round(const vec3_t& v) {
    vec3_t out;

    vec3_round(out, v);

    return out;
}

void vec3m_round(vec3_t& out) {
    vec3_round(out, out);
}

void vec3_snap(vec3_t& out, const vec3_t& v, const vec3_t c) {
    out.x = msnap(v.x, c.x);
    out.y = msnap(v.y, c.y);
    out.z = msnap(v.z, c.z);
}

vec3_t vec3n_snap(const vec3_t& v, const vec3_t c) {
    vec3_t out;

    vec3_snap(out, v, c);

    return out;
}

void vec3m_snap(vec3_t& out, const vec3_t c) {
    vec3_snap(out, out, c);
}

// comparison
bool vec3_equals(const vec3_t& v0, const vec3_t& v1, num_t e) {
    return mabs(v0.x - v1.x) < e && mabs(v0.y - v1.y) < e && mabs(v0.z - v1.z) < e;
}

// string
void vec3_str(const vec3_t& v, char* str) {
    sprintf(str, "vec3(%f, %f, %f)", num_t(v.x), num_t(v.y), num_t(v.z));
}
