#type vertex
#version 430 core
layout(location = 0) in vec3 i_position;
layout(location = 1) in vec3 i_normal;
layout(location = 2) in vec2 i_tex_coord;
uniform mat4 u_projection;
uniform mat4 u_view;
out vec3 v_normal;
out vec2 v_tex_coord;
out vec3 v_frag_pos;

void main() {
    gl_Position = u_projection * u_view * vec4(i_position, 1.0);
    v_normal = i_normal;
    v_tex_coord = v_tex_coord;
    v_frag_pos = vec3(vec4(i_position, 1.0));
}

#type fragment
#version 430 core
precision mediump float;
in vec3 v_normal;
in vec2 v_tex_coord;
in vec3 v_frag_pos;
out vec4 o_frag_color;
uniform vec3 u_cam_pos;
uniform vec3 u_sun_direction;
uniform vec3 u_sun_color;

void main() {
    vec3 normal = normalize(v_normal);
    vec3 light_dir = normalize(u_sun_direction);
    float diffuse = max(dot(normal, light_dir), 0.0);
    vec3 ambient = vec3(0.1);

    vec3 view_dir = normalize(u_cam_pos - v_frag_pos);
    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float specular_strength = 0.8;
    vec3 light_color = vec3(1.0);
    vec3 specular = specular_strength * spec * light_color;
    vec3 result = (ambient + diffuse * u_sun_color + specular);

    o_frag_color = vec4(result, 1.0);
}
