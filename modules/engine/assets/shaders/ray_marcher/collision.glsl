#type compute
#version 430 core
layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout(rgba32f, binding = 1) uniform image2D u_texture;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform float u_near;
uniform float u_far;
uniform vec3 u_fract_translation;
uniform vec3 u_fract_rotation;
uniform float u_fract_scaling;
uniform vec3 u_fract_color;
uniform float u_time;
uniform int u_fract_iter;
uniform float u_radius;

#include "map.glsl"

vec3 calc_normal(vec3 p, float d) {
    vec2 k = vec2(1.0, -1.0);

    return normalize(
        k.xyy * map(p + k.xyy * d).d +
        k.yyx * map(p + k.yyx * d).d +
        k.yxy * map(p + k.yxy * d).d +
        k.xxx * map(p + k.xxx * d).d
    );
}

vec4 calc_dir() {
    mat4 proj_inv = inverse(u_projection);
    mat4 view_inv = inverse(u_view);
    vec3 u_position = view_inv[3].xyz;
    float d = map(u_position).d - u_radius;

    return vec4(calc_normal(u_position, d), d);
}

void main() {
    imageStore(u_texture, ivec2(gl_GlobalInvocationID.xy), calc_dir());
}
