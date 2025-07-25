// packing
num_t vec3_pack(const vec3_t& v) {
    return ((v.x & 0xff) << 16) | ((v.y & 0xff) << 8) | (v.z & 0xff);
}

void vec3_unpack(vec3_t& out, num_t x) {
    out.x = (x >> 16) & 0xff;
    out.y = (x >> 8) & 0xff;
    out.z = x & 0xff;
}

vec3_t vec3n_unpack(num_t x) {
    vec3_t out;

    vec3_unpack(out, x);

    return out;
}

// comparison
bool vec3_equals(const vec3_t& v0, const vec3_t& v1) {
    return v0.x == v1.x && v0.y == v1.y && v0.z == v1.z;
}
