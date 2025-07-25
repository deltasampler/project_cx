#type vertex
#version 460 core
out vec2 v_tex_coord;

const vec2 positions[4] = vec2[](
    vec2(-1.0, -1.0),
    vec2(1.0, -1.0),
    vec2(-1.0, 1.0),
    vec2(1.0, 1.0)
);

const vec2 tex_coords[4] = vec2[](
    vec2(0.0, 0.0),
    vec2(1.0, 0.0),
    vec2(0.0, 1.0),
    vec2(1.0, 1.0)
);

void main() {
    vec2 position = positions[gl_VertexID];
    gl_Position = vec4(position, 0.0, 1.0);
    v_tex_coord = tex_coords[gl_VertexID];
}

#type fragment
#version 460 core
precision mediump float;
out vec4 o_frag_color;
in vec2 v_tex_coord;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec3 u_bottom_color;
uniform vec3 u_middle_color;
uniform vec3 u_top_color;
uniform vec3 u_sun_direction;
uniform float u_sun_scale;
uniform vec3 u_sun_color;

void main() {
    mat4 proj_inv = inverse(u_projection);
    mat4 view_inv = inverse(u_view);
    vec3 pos = view_inv[3].xyz;
    vec2 uv = v_tex_coord * 2.0 - 1.0;
    vec4 clip = proj_inv * vec4(uv, 0.0, 0.0);
    vec4 view = view_inv * vec4(clip.xy, -1.0, 0.0);
    vec3 rd = normalize(view.xyz);

    float sun = (dot(rd, normalize(-u_sun_direction)) + 1.0) / 2.0;
    vec3 sun_color = u_sun_color * smoothstep(u_sun_scale, 0.0, sun);
    vec3 color;

    if (rd.y < 0.0) {
        color = mix(u_bottom_color, u_middle_color, 1.0 + rd.y) + sun_color;
    } else {
        color = mix(u_middle_color, u_top_color, rd.y) + sun_color;
    }

    o_frag_color = vec4(color, 1.0);
}
