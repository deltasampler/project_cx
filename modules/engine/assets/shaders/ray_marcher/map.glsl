struct res_t {
    float d;
    vec3 c;
};

// fractal functions
void rot_x(inout vec3 p, float c, float s) {
    p.yz = vec2(p.y * c + p.z * s, p.z * c - p.y * s);
}

void rot_y(inout vec3 p, float c, float s) {
    p.xz = vec2(p.x * c - p.z * s, p.z * c + p.x * s);
}

void rot_z(inout vec3 p, float c, float s) {
    p.xy = vec2(p.x * c + p.y * s, p.y * c - p.x * s);
}

void rot_x(inout vec3 p, float a) {
    rot_x(p, cos(a), sin(a));
}

void rot_y(inout vec3 p, float a) {
    rot_y(p, cos(a), sin(a));
}

void rot_z(inout vec3 p, float a) {
    rot_z(p, cos(a), sin(a));
}

void fold_plane(inout vec3 p, vec3 n, float d) {
    p -= 2.0 * min(0.0, dot(p, n) - d) * n;
}

void fold_sierpinski(inout vec3 p) {
    p.xy -= min(p.x + p.y, 0.0);
    p.xz -= min(p.x + p.z, 0.0);
    p.yz -= min(p.y + p.z, 0.0);
}

vec3 aces_film(vec3 x) {
    float a = 2.51;
    float b = 0.03;
    float c = 2.43;
    float d = 0.59;
    float e = 0.14;

    return (x * (a * x + b)) / (x * (c * x + d) + e);
}

void fold_menger(inout vec3 p) {
    float a = min(p.x - p.y, 0.0);
    p.x -= a;
    p.y += a;

    a = min(p.x - p.z, 0.0);
    p.x -= a;
    p.z += a;

    a = min(p.y - p.z, 0.0);
    p.y -= a;
    p.z += a;
}

void fold_box(inout vec3 p, vec3 b) {
    p = clamp(p, -b, b) * 2.0 - p;
}

// position functions
vec3 p_translate(vec3 p, vec3 t) {
    return p - t;
}

vec3 p_rep(vec3 p, vec3 s) {
    return p - s * round(p / s);
}

// signed distance functions
float sd_sphere(vec3 p, float r) {
    return length(p) - r;
}

float sd_box(vec3 p, vec3 b) {
    vec3 q = abs(p) - b;

    return length(max(q, 0.0)) + min(max(q.x, max(q.y, q.z)), 0.0);
}

// combination functions
float op_union(float d0, float d1) {
    return min(d0, d1);
}

res_t op_union(res_t r0, res_t r1) {
    if (r0.d < r1.d) {
        return r0;
    }

    return r1;
}

float op_union_smooth(float d0, float d1, float k) {
    float h = clamp(0.5 + 0.5 * (d1 - d0) / k, 0.0, 1.0);

    return mix(d1, d0, h) - k * h * (1.0 - h);
}

res_t op_union_smooth(res_t r0, res_t r1, float k) {
    float h = clamp(0.5 + 0.5 * (r1.d - r0.d) / k, 0.0, 1.0);

    return res_t(mix(r1.d, r0.d, h) - k * h * (1.0 - h), mix(r0.c, r1.c, k));
}

// fractal
res_t sd_fractal(vec3 p, int iter) {
    res_t res;
    float scaling = 1.0;
    vec3 orbit = vec3(0.0);

    for (int i = 0; i < iter; ++i) {
        p = abs(p);

        rot_z(p, u_fract_rotation.z);

        fold_menger(p);

        rot_x(p, u_fract_rotation.x);

        p *= u_fract_scaling;
        scaling *= u_fract_scaling;

        p += u_fract_translation;

        orbit = max(orbit, p * u_fract_color);
    }

    res.d = sd_box(p, vec3(6.0)) / scaling;
    res.c = orbit;

    return res;
}

// map
res_t map(vec3 p) {
    return sd_fractal(p, u_fract_iter);
}
