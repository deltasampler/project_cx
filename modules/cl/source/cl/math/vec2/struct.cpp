vec2_t pre(vec2)(num_t x) {
    vec2_t out;

    out.x = x;
    out.y = x;

    return out;
}

vec2_t pre(vec2)(num_t x, num_t y) {
    vec2_t out;

    out.x = x;
    out.y = y;

    return out;
}

void vec2_set(vec2_t& out, num_t x, num_t y) {
    out.x = x;
    out.y = y;
}

void vec2_zero(vec2_t& out) {
    out.x = num_t(0);
    out.y = num_t(0);
}

vec2_t pre(vec2n_zero)() {
    vec2_t out;

    vec2_zero(out);

    return out;
}

void vec2_copy(vec2_t& out, const vec2_t& v) {
    out.x = v.x;
    out.y = v.y;
}

vec2_t vec2n_copy(const vec2_t& v) {
    vec2_t out;

    vec2_copy(out, v);

    return out;
}
