#type compute
#version 460 core
layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;
layout(binding = 0, rgba32f) uniform image2D u_texture;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform float u_march_limit;
uniform float u_shadow_limit;
uniform float u_near;
uniform float u_far;
uniform vec3 u_light_dir;
uniform vec3 u_light_color;
uniform vec3 u_sky_low_color;
uniform vec3 u_sky_high_color;
uniform vec3 u_fract_translation;
uniform vec3 u_fract_rotation;
uniform float u_fract_scaling;
uniform vec3 u_fract_color;
uniform float u_time;
uniform float u_ambient_stren;
uniform float u_specular_stren;
uniform float u_sun_size;
uniform int u_aa_samples;
uniform int u_fract_iter;

#define FRACT_ITER 16
#define ANTIALIASING_SAMPLES 1
#define AMBIENT_OCCLUSION_COLOR_DELTA vec3(0.7)
#define AMBIENT_OCCLUSION_STRENGTH 0.008
#define SUN_SHARPNESS 2.0
#define SUN_SIZE 0.002

#include "map.glsl"

// marcher
struct mar_t {
    vec3 pos;
    vec3 ray_dir;
    float dist;
    float dist_sum;
    float dist_min;
    float steps;
    int sign;
};

void march(inout mar_t mar, inout res_t res, float lim, float near, float far) {
    res = map(mar.pos);
    mar.dist = res.d;
    mar.dist_sum = 0.0;
    mar.dist_min = 1.0;
    mar.steps = 0.0;
    mar.sign = 0;

    for (; mar.steps < lim; mar.steps += 1.0) {
        if (mar.dist_sum < -0.1) {
            mar.sign = -1;

            break;
        }

        if (mar.dist < near) {
            mar.steps += mar.dist / near;
            mar.sign = 0;

            break;
        }

        if (mar.dist_sum > far) {
            mar.sign = 1;

            break;
        }

        mar.dist_sum += mar.dist;
        mar.pos += mar.ray_dir * mar.dist;
        mar.dist_min = min(mar.dist_min, mar.dist / mar.dist_sum);
        res = map(mar.pos);
        mar.dist = res.d;
    }
}

float march_shadow(vec3 pos, vec3 ray_dir, float march_limit, float near, float far) {
    float dist_sum = near;

        for (float i = 0.0; i < march_limit && dist_sum < far; i += 1.0) {
        float dist = map(pos + ray_dir * dist_sum).d;

        if (dist < near) {
            return 0.0;
        }

        dist_sum += dist;
    }

    return 1.0;
}

vec3 calc_normal(vec3 p, float d) {
    vec2 k = vec2(1.0, -1.0);

    return normalize(
        k.xyy * map(p + k.xyy * d).d +
        k.yyx * map(p + k.yyx * d).d +
        k.yxy * map(p + k.yxy * d).d +
        k.xxx * map(p + k.xxx * d).d
    );
}

vec3 smooth_color(vec3 p, vec3 s0, vec3 s1, float d) {
    return (
        map(p + s0 * d).c +
        map(p - s0 * d).c +
        map(p + s1 * d).c +
        map(p - s1 * d).c
    ) / 4.0;
}

vec3 render_skybox(vec3 ray_dir, vec3 light_dir, int sign) {
    vec3 col = mix(u_sky_low_color, u_sky_high_color, ray_dir.y);
    float sun_size = u_sun_size / 100.0;

    if (sign == 1) {
        float sun_spec = dot(ray_dir, light_dir) - 1.0 + sun_size;
        sun_spec = min(exp(sun_spec * SUN_SHARPNESS / sun_size), 1.0);
        col += u_light_color * sun_spec;
    }

    return col;
}

vec3 render(vec3 pos, vec3 ray_dir) {
    mar_t mar;
    mar.pos = pos;
    mar.ray_dir = ray_dir;

    res_t res;

    march(mar, res, u_march_limit, u_near, u_far);

    vec3 col = vec3(0.0);
    vec3 light_dir = normalize(u_light_dir);
    vec3 norm = calc_normal(mar.pos, u_near * 0.5);
    vec3 refl_dir = reflect(mar.ray_dir, norm);

    // background
    vec3 bg_color = render_skybox(mar.ray_dir, light_dir, mar.sign);

    if (mar.sign == 0) {
        float depth = mar.dist_sum / u_far;

        // not sure why
        // mar.pos -= norm * mar.dist;

        // res color
        vec3 res_col = clamp(res.c, 0.0, 1.0);

        // filtering
        vec3 s0 = normalize(cross(mar.ray_dir, norm));
        vec3 s1 = cross(s0, norm);
        res_col = clamp(smooth_color(mar.pos, s0, s1, u_near * 0.5), 0.0, 1.0);

        // ambient
        vec3 ambient = u_light_color * bg_color * u_ambient_stren;

        // diffuse
        float diffuse_factor = clamp(dot(norm, light_dir), 0.0, 1.0);
        vec3 diffuse = u_light_color * diffuse_factor;

        // shadow
        vec3 light_pos = mar.pos + norm * u_near * 100.0;
        diffuse *= march_shadow(light_pos, light_dir, u_shadow_limit, u_near, u_far);

        // specular
        float specular_factor = pow(max(dot(refl_dir, light_dir), 0.0), 16.0);
        vec3 specular = u_light_color * specular_factor * u_specular_stren;

        col += res_col * (ambient + diffuse + specular);

        // ao
        float ao_factor = 1.0 / (1.0 + mar.steps * AMBIENT_OCCLUSION_STRENGTH);
        col += (1.0 - ao_factor) * AMBIENT_OCCLUSION_COLOR_DELTA;

        // fog
        vec3 fog = depth * bg_color;

        col = (1.0 - depth) * col + fog;
    } else if (mar.sign == 1) {
        col += bg_color;
    }

    return col;
}

void main() {
    ivec2 image_pos = ivec2(gl_GlobalInvocationID.xy);
    ivec2 image_size = imageSize(u_texture);

    mat4 proj_inv = inverse(u_projection);
    mat4 view_inv = inverse(u_view);

    vec3 pos = view_inv[3].xyz;
    vec3 col = vec3(0.0);

    for (int i = 0; i < u_aa_samples; ++i) {
        for (int j = 0; j < u_aa_samples; ++j) {
            vec2 delta = vec2(i, j) / float(u_aa_samples);
            // vec2 tex_coord = (vec2(image_pos) + delta) / vec2(image_size);
            vec2 tex_coord = vec2(image_pos) / vec2(image_size);
            vec2 uv = tex_coord * 2.0 - 1.0;
            vec4 clip = proj_inv * vec4(uv, 0.0, 0.0);
            vec4 view = view_inv * vec4(clip.xy, -1.0, 0.0);
            vec3 ray_dir = normalize(view.xyz);

            col += render(pos, ray_dir);
        }
    }

    col /= float(u_aa_samples * u_aa_samples);

    imageStore(u_texture, image_pos, vec4(col, 1.0));
}
