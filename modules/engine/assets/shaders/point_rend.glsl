#type vertex
#version 460 core
layout(location = 0) in vec3 i_position;
layout(location = 1) in float i_size;
layout(location = 2) in vec3 i_color;

out geometry_data {
    float size;
    vec3 color;
} v_gd;

void main() {
    gl_Position = vec4(i_position, 1.0);
    v_gd.size = i_size;
    v_gd.color = i_color;
}

#type geometry
#version 460 core
layout (points) in;
layout (triangle_strip, max_vertices = 4) out;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec3 u_camera_right;
uniform vec3 u_camera_up;
out vec3 v_color;
out vec2 v_tex_coord;

in geometry_data {
    float size;
    vec3 color;
} v_gd[];

void main() {
    vec3 p = gl_in[0].gl_Position.xyz;
    float hs = v_gd[0].size / 2.0f;
    mat4 pv = u_projection * u_view;

    gl_Position = pv * vec4(p - u_camera_right * hs + u_camera_up * hs, 1.0);
    v_color = v_gd[0].color;
    v_tex_coord = vec2(0.0, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p - u_camera_right * hs - u_camera_up * hs, 1.0);
    v_tex_coord = vec2(0.0, 1.0);
    EmitVertex();

    gl_Position = pv * vec4(p + u_camera_right * hs + u_camera_up * hs, 1.0);
    v_tex_coord = vec2(1.0, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p + u_camera_right * hs - u_camera_up * hs, 1.0);
    v_tex_coord = vec2(1.0, 1.0);
    EmitVertex();
}

#type fragment
#version 460 core
precision mediump float;
in vec3 v_color;
in vec2 v_tex_coord;
out vec4 o_frag_color;

void main() {
    vec2 ndc = vec2(v_tex_coord.x * 2.0 - 1.0, v_tex_coord.y * -2.0 + 1.0);
    float d = dot(ndc, ndc);

    if (d > 1.0) {
        discard;
    }

    o_frag_color = vec4(v_color, 1.0);
}
