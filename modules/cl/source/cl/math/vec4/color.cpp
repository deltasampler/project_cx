// color
vec4_t pre(rgba)(num_t r, num_t g, num_t b, num_t a) {
    vec4_t out;

    out.x = r / num_t(255.0);
    out.y = g / num_t(255.0);
    out.z = b / num_t(255.0);
    out.z = b / num_t(255.0);

    return out;
}

vec4_t pre(hexa)(s32 h) {
    vec4_t out;

    out.x = ((h >> 24) & 0xff) / num_t(255.0);
    out.y = ((h >> 16) & 0xff) / num_t(255.0);
    out.z = ((h >> 8) & 0xff) / num_t(255.0);
    out.w = (h & 0xff) / num_t(255.0);

    return out;
}
