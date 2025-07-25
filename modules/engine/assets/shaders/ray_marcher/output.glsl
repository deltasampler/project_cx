#type vertex
#version 460 core
out vec2 v_tex_coord;

const vec2 positions[4] = vec2[4](
    vec2(-1.0, -1.0),
    vec2(-1.0, 1.0),
    vec2(1.0, -1.0),
    vec2(1.0, 1.0)
);

const vec2 tex_coords[4] = vec2[4](
    vec2(0.0, 0.0),
    vec2(0.0, 1.0),
    vec2(1.0, 0.0),
    vec2(1.0, 1.0)
);

void main() {
    gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);
    v_tex_coord = tex_coords[gl_VertexID];
}

#type fragment
#version 460 core
precision mediump float;
out vec4 o_frag_color;
in vec2 v_tex_coord;
uniform sampler2D u_texture;

void main() {
    o_frag_color = texture(u_texture, v_tex_coord);
}
