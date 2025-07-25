#type vertex
#version 460 core
layout(location = 0) in vec3 i_position;
layout(location = 1) in float i_size;
layout(location = 2) in vec3 i_normal;
layout(location = 3) in vec3 i_color;

out geometry_data {
    float size;
    vec3 normal;
    vec3 color;
} v_gd;

void main() {
    gl_Position = vec4(i_position, 1.0);
    v_gd.size = i_size;
    v_gd.normal = i_normal;
    v_gd.color = i_color;
}

#type geometry
#version 460 core
layout (lines) in;
layout (triangle_strip, max_vertices = 7) out;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec3 u_camera_position;
uniform bool u_should_follow;
out vec3 v_color;

in geometry_data {
    float size;
    vec3 normal;
    vec3 color;
} v_gd[];

void main() {
    vec3 p1 = gl_in[0].gl_Position.xyz;
    vec3 p2 = gl_in[1].gl_Position.xyz;
    float size1 = v_gd[0].size;
    float size2 = v_gd[1].size;
    vec3 color1 = v_gd[0].color;
    vec3 color2 = v_gd[1].color;
    vec3 normal1 = v_gd[0].normal;
    vec3 normal2 = v_gd[1].normal;
    mat4 pv = u_projection * u_view;
    vec3 line_dir = normalize(p2 - p1);
    vec3 line_mid = (p1 + p2) / 2.0;
    vec3 cam_dir = normalize(line_mid - u_camera_position);
    vec3 dir1 = u_should_follow ? cam_dir : normal1;
    vec3 dir2 = u_should_follow ? cam_dir : normal2;
    vec3 perp1 = normalize(cross(line_dir, dir1));
    vec3 perp2 = normalize(cross(line_dir, dir2));

    float cap_width = size2 * 2.0;
    float cap_length = size2 * 4.0;
    vec3 cap_pos = p2 - line_dir * cap_length;

    v_color = color1;
    gl_Position = pv * vec4(p1 - perp1 * size1, 1.0);
    EmitVertex();

    gl_Position = pv * vec4(p1 + perp1 * size1, 1.0);
    EmitVertex();

    v_color = color2;
    gl_Position = pv * vec4(cap_pos - perp2 * size2, 1.0);
    EmitVertex();

    gl_Position = pv * vec4(cap_pos + perp2 * size2, 1.0);
    EmitVertex();

    EndPrimitive();

    v_color = color2;
    gl_Position = pv * vec4(cap_pos - perp2 * cap_width, 1.0);
    EmitVertex();

    gl_Position = pv * vec4(cap_pos + perp2 * cap_width, 1.0);
    EmitVertex();

    gl_Position= pv * vec4(p2, 1.0);
    EmitVertex();
}

#type fragment
#version 460 core
precision mediump float;
in vec3 v_color;
out vec4 o_frag_color;

void main() {
    o_frag_color = vec4(v_color, 1.0);
}
