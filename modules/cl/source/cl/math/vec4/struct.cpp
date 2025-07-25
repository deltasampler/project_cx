vec4_t pre(vec4)(num_t x) {
    vec4_t out;

    out.x = x;
    out.y = x;
    out.z = x;
    out.w = x;

    return out;
}

vec4_t pre(vec4)(num_t x, num_t y, num_t z, num_t w) {
    vec4_t out;

    out.x = x;
    out.y = y;
    out.z = z;
    out.w = w;

    return out;
}

void vec4_set(vec4_t& out, num_t x, num_t y, num_t z, num_t w) {
    out.x = x;
    out.y = y;
    out.z = z;
    out.w = w;
}

void vec4_zero(vec4_t& out) {
    out.x = num_t(0);
    out.y = num_t(0);
    out.z = num_t(0);
    out.w = num_t(0);
}

vec4_t pre(vec4n_zero)() {
    vec4_t out;

    vec4_zero(out);

    return out;
}

void vec4_copy(vec4_t& out, const vec4_t& v) {
    out.x = v.x;
    out.y = v.y;
    out.z = v.z;
    out.w = v.w;
}

vec4_t vec4n_copy(const vec4_t& v) {
    vec4_t out;

    vec4_copy(out, v);

    return out;
}
