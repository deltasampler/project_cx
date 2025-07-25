#type vertex
#version 430 core
layout(location = 0) in vec3 i_position;
layout(location = 1) in vec3 i_size;
layout(location = 2) in vec3 i_color;

out geometry_data {
    vec3 size;
    vec3 color;
} v_gd;

void main() {
    gl_Position = vec4(i_position, 1.0);
    v_gd.size = i_size;
    v_gd.color = i_color;
}

#type geometry
#version 430 core
layout (points) in;
layout (triangle_strip, max_vertices = 24) out;
uniform mat4 u_projection;
uniform mat4 u_view;
out vec2 v_width;
out vec3 v_color;
out vec2 v_tex_coord;

#define width 0.2

in geometry_data {
    vec3 size;
    vec3 color;
} v_gd[];

void draw_quad(vec3 p1, vec3 p2, vec3 p3, vec3 p4) {
    mat4 pv = u_projection * u_view;

    gl_Position = pv * vec4(p1, 1.0);
    v_tex_coord = vec2(0.0, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p2, 1.0);
    v_tex_coord = vec2(0.0, 1.0);
    EmitVertex();

    gl_Position = pv * vec4(p3, 1.0);
    v_tex_coord = vec2(1.0, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p4, 1.0);
    v_tex_coord = vec2(1.0, 1.0);
    EmitVertex();

    EndPrimitive();
}

void main() {
    vec3 p = gl_in[0].gl_Position.xyz;
    vec3 size = v_gd[0].size;
    vec3 color = v_gd[0].color;

    vec3 half_size = size / 2.0;
    vec3 p1 = p + vec3(-half_size.x, half_size.y, -half_size.z);
    vec3 p2 = p + vec3(-half_size.x, -half_size.y, -half_size.z);
    vec3 p3 = p + vec3(-half_size.x, half_size.y, half_size.z);
    vec3 p4 = p + vec3(-half_size.x, -half_size.y, half_size.z);
    vec3 p5 = p + vec3(half_size.x, half_size.y, half_size.z);
    vec3 p6 = p + vec3(half_size.x, -half_size.y, half_size.z);
    vec3 p7 = p + vec3(half_size.x, half_size.y, -half_size.z);
    vec3 p8 = p + vec3(half_size.x, -half_size.y, -half_size.z);

    v_color = color;
    v_width = vec2(width / size.z, width / size.y);
    draw_quad(p1, p2, p3, p4);
    draw_quad(p5, p6, p7, p8);

    v_width = vec2(width / size.x, width / size.y);
    draw_quad(p3, p4, p5, p6);
    draw_quad(p7, p8, p1, p2);

    v_width = vec2(width / size.x, width / size.z);
    draw_quad(p1, p3, p7, p5);
    draw_quad(p8, p6, p2, p4);
}

#type fragment
#version 430 core
precision mediump float;
in vec2 v_width;
in vec3 v_color;
in vec2 v_tex_coord;
out vec4 o_frag_color;

void main() {
    vec2 uv = v_tex_coord;

    if (uv.x > v_width.x && uv.x < (1.0 - v_width.x) && uv.y > v_width.y && uv.y < (1.0 - v_width.y)) {
        discard;
    }

    o_frag_color = vec4(v_color, 1.0);
}
