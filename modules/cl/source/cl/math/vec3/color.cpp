// color
vec3_t pre(rgb)(num_t r, num_t g, num_t b) {
    vec3_t out;

    out.x = r / num_t(255.0);
    out.y = g / num_t(255.0);
    out.z = b / num_t(255.0);

    return out;
}

vec3_t pre(hex)(s32 h) {
    vec3_t out;

    out.x = ((h >> 16) & 0xff) / num_t(255.0);
    out.y = ((h >> 8) & 0xff) / num_t(255.0);
    out.z = (h & 0xff) / num_t(255.0);

    return out;
}
