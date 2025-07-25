// packing
num_t vec4_pack(const vec4_t& v) {
    return ((v.x & 0xff) << 24) | ((v.y & 0xff) << 16) | ((v.z & 0xff) << 8) | (v.w & 0xff);
}

void vec4_unpack(vec4_t& out, num_t x) {
    out.x = (x >> 24) & 0xff;
    out.y = (x >> 16) & 0xff;
    out.z = (x >> 8) & 0xff;
    out.w = x & 0xff;
}

vec4_t vec4n_unpack(num_t x) {
    vec4_t out;

    vec4_unpack(out, x);

    return out;
}

// comparison
bool vec4_equals(const vec4_t& v0, const vec4_t& v1) {
    return v0.x == v1.x && v0.y == v1.y && v0.z == v1.z && v0.w == v1.w;
}
