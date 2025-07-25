#type vertex
#version 430 core
layout(location = 0) in vec3 i_position;
layout(location = 1) in vec3 i_size;
layout(location = 2) in vec3 i_color;
uniform mat4 u_model;

out geometry_data {
    vec3 size;
    vec3 color;
} v_gd;

void main() {
    gl_Position = u_model * vec4(i_position, 1.0);
    v_gd.size = i_size;
    v_gd.color = i_color;
}

#type geometry
#version 430 core
layout (points) in;
layout (triangle_strip, max_vertices = 4) out;
uniform mat4 u_projection;
uniform mat4 u_view;
out vec3 v_size;
out vec3 v_color;
out vec2 v_tex_coord;

#define width 0.2

in geometry_data {
    vec3 size;
    vec3 color;
} v_gd[];

void main() {
    vec3 p = gl_in[0].gl_Position.xyz;
    vec3 size = v_gd[0].size;
    vec3 color = v_gd[0].color;
    mat4 pv = u_projection * u_view;

    vec3 half_size = size / 2.0;
    vec3 p1 = p + vec3(-half_size.x, 0.0, -half_size.z);
    vec3 p2 = p + vec3(-half_size.x, 0.0, half_size.z);
    vec3 p3 = p + vec3(half_size.x, 0.0, -half_size.z);
    vec3 p4 = p + vec3(half_size.x, 0.0, half_size.z);

    v_color = color;
    v_size = size;
    gl_Position = pv * vec4(p1, 1.0);
    v_tex_coord = vec2(0.0, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p2, 1.0);
    v_tex_coord = vec2(0.0, size.z);
    EmitVertex();

    gl_Position = pv * vec4(p3, 1.0);
    v_tex_coord = vec2(size.x, 0.0);
    EmitVertex();

    gl_Position = pv * vec4(p4, 1.0);
    v_tex_coord = vec2(size.x, size.z);
    EmitVertex();

    EndPrimitive();
}

#type fragment
#version 430 core
precision mediump float;
in vec3 v_size;
in vec3 v_color;
in vec2 v_tex_coord;
out vec4 o_frag_color;

float pristine_grid( in vec2 uv, vec2 line_width) {
    vec2 ddx = dFdx(uv);
    vec2 ddy = dFdy(uv);
    vec2 uv_deriv = vec2(length(vec2(ddx.x, ddy.x)), length(vec2(ddx.y, ddy.y)));

    bvec2 invert_line = bvec2(line_width.x > 0.5, line_width.y > 0.5);
    vec2 target_width = vec2(
        invert_line.x ? 1.0 - line_width.x : line_width.x,
        invert_line.y ? 1.0 - line_width.y : line_width.y
    );

    vec2 draw_width = clamp(target_width, uv_deriv, vec2(0.5));
    vec2 lineAA = uv_deriv * 1.5;

    vec2 grid_uv = abs(fract(uv) * 2.0 - 1.0);
    grid_uv.x = invert_line.x ? grid_uv.x : 1.0 - grid_uv.x;
    grid_uv.y = invert_line.y ? grid_uv.y : 1.0 - grid_uv.y;

    vec2 grid2 = smoothstep(draw_width + lineAA, draw_width - lineAA, grid_uv);

    grid2 *= clamp(target_width / draw_width, 0.0, 1.0);
    grid2 = mix(grid2, target_width, clamp(uv_deriv * 2.0 - 1.0, 0.0, 1.0));
    grid2.x = invert_line.x ? 1.0 - grid2.x : grid2.x;
    grid2.y = invert_line.y ? 1.0 - grid2.y : grid2.y;

    return mix(grid2.x, 1.0, grid2.y);
}

void main() {
    vec2 uv = v_tex_coord;

    o_frag_color = vec4(v_color, pristine_grid(uv, vec2(0.03)));
}
