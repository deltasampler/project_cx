#type vertex
#version 430 core
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
#version 430 core
layout (lines) in;
layout (triangle_strip, max_vertices = 86) out;
uniform mat4 u_projection;
uniform mat4 u_view;
out vec3 v_color;

in geometry_data {
    float size;
    vec3 color;
} v_gd[];

#define PI 3.14159265359
#define sub 12
#define angle PI * 2.0 / sub

void main() {
    vec3 p1 = gl_in[0].gl_Position.xyz;
    vec3 p2 = gl_in[1].gl_Position.xyz;
    float size1 = v_gd[0].size;
    float size2 = v_gd[1].size;
    vec3 color1 = v_gd[0].color;
    vec3 color2 = v_gd[1].color;
    vec3 line_dir = normalize(p2 - p1);
    vec3 perp_test = normalize(cross(line_dir, vec3(0.0, 1.0, 0.0)));
    vec3 perp1 = dot(perp_test, perp_test) > 0.0 ? perp_test : normalize(cross(line_dir, vec3(1.0, 0.0, 0.0)));
    vec3 perp2 = normalize(cross(line_dir, perp1));
    float cap_width = size2;
    float cap_length = size2 * 2.0;
    vec3 cap_pos = p2 - line_dir * cap_length;
    mat4 pv = u_projection * u_view;

    // Body start
    v_color = color1;
    gl_Position = pv * vec4(p1 + perp1 * size1, 1.0);
    EmitVertex();

    for (int i = 1; i < ceil(sub / 2); ++i) {
        float x1 = cos(angle * i);
        float y1 = sin(angle * i);
        float x2 = cos(angle * (i + 1));
        float y2 = sin(angle * (i + 1));
        vec3 point1 = perp1 * x1 - perp2 * y1;
        vec3 point2 = perp1 * x1 + perp2 * y1;

        gl_Position = pv * vec4(p1 + point1 * size1, 1.0);
        EmitVertex();

        gl_Position = pv * vec4(p1 + point2 * size1, 1.0);
        EmitVertex();
    }

    if (sub % 2 == 0) {
        gl_Position = pv * vec4(p1 - perp1 * size1, 1.0);
        EmitVertex();
    }

    EndPrimitive();

    // Body
    for (float i = 0; i < (sub + 1); ++i) {
        float x = cos(angle * i);
        float y = sin(angle * i);
        vec3 point = perp1 * x + perp2 * y;

        v_color = color2;
        gl_Position = pv * vec4(cap_pos + point * size1, 1.0);
        EmitVertex();

        v_color = color1;
        gl_Position = pv * vec4(p1 + point * size1, 1.0);
        EmitVertex();
    }

    EndPrimitive();

    // Cap start
    v_color = color2;
    gl_Position = pv * vec4(cap_pos + perp1 * cap_width, 1.0);
    EmitVertex();

    for (int i = 1; i < ceil(sub / 2); ++i) {
        float x1 = cos(angle * i);
        float y1 = sin(angle * i);
        float x2 = cos(angle * (i + 1));
        float y2 = sin(angle * (i + 1));
        vec3 point1 = perp1 * x1 - perp2 * y1;
        vec3 point2 = perp1 * x1 + perp2 * y1;

        gl_Position = pv * vec4(cap_pos + point1 * cap_width, 1.0);
        EmitVertex();

        gl_Position = pv * vec4(cap_pos + point2 * cap_width, 1.0);
        EmitVertex();
    }

    if (sub % 2 == 0) {
        gl_Position = pv * vec4(cap_pos - perp1 * cap_width, 1.0);
        EmitVertex();
    }

    EndPrimitive();

    // Cap
    v_color = color2;

    for (int i = 0; i < sub; ++i) {
        float x1 = cos(angle * i);
        float y1 = sin(angle * i);
        float x2 = cos(angle * (i + 1));
        float y2 = sin(angle * (i + 1));
        vec3 point1 = perp1 * x1 + perp2 * y1;
        vec3 point2 = perp1 * x2 + perp2 * y2;

        gl_Position = pv * vec4(cap_pos + point1 * cap_width, 1.0);
        EmitVertex();

        gl_Position = pv * vec4(cap_pos + point2 * cap_width, 1.0);
        EmitVertex();

        gl_Position = pv * vec4(p2, 1.0);
        EmitVertex();

        EndPrimitive();
    }
}

#type fragment
#version 430 core
precision mediump float;
in vec3 v_color;
out vec4 o_frag_color;

void main() {
    o_frag_color = vec4(v_color, 1.0);
}
