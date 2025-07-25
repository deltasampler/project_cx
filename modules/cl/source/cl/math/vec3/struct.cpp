vec3_t pre(vec3)(num_t x) {
    vec3_t out;

    out.x = x;
    out.y = x;
    out.z = x;

    return out;
}

vec3_t pre(vec3)(num_t x, num_t y, num_t z) {
    vec3_t out;

    out.x = x;
    out.y = y;
    out.z = z;

    return out;
}

void vec3_set(vec3_t& out, num_t x, num_t y, num_t z) {
    out.x = x;
    out.y = y;
    out.z = z;
}

void vec3_zero(vec3_t& out) {
    out.x = num_t(0);
    out.y = num_t(0);
    out.z = num_t(0);
}

vec3_t pre(vec3n_zero)() {
    vec3_t out;

    vec3_zero(out);

    return out;
}

void vec3_copy(vec3_t& out, const vec3_t& v) {
    out.x = v.x;
    out.y = v.y;
    out.z = v.z;
}

vec3_t vec3n_copy(const vec3_t& v) {
    vec3_t out;

    vec3_copy(out, v);

    return out;
}
