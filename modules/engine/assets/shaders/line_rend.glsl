#type vertex
#version 430 core
uniform int u_length;

struct line_point_t {
    float[3] position;
    float size;
    float[3] normal;
    float[3] color;
    uint data;
};

layout(std430, binding = 0) buffer vertex_data {
    line_point_t line_points[];
};

out geometry_data {
    vec3 prev_pos;
    vec3 next_pos;

    float curr_size;
    float next_size;

    vec3 curr_normal;
    vec3 next_normal;

    bool prev_data;
    bool curr_data;
    bool next_data;
} v_gd;

void main() {
    line_point_t prev = line_points[(gl_VertexID - 1 + u_length) % u_length];
    line_point_t curr = line_points[gl_VertexID];
    line_point_t next = line_points[(gl_VertexID + 1) % u_length];

    gl_Position = vec4(curr.position[0], curr.position[1], curr.position[2], 1.0);

    v_gd.prev_pos = vec3(prev.position[0], prev.position[1], prev.position[2]);
    v_gd.next_pos = vec3(next.position[0], next.position[1], next.position[2]);

    v_gd.curr_size = curr.size;
    v_gd.next_size = next.size;

    v_gd.curr_normal = vec3(curr.normal[0], curr.normal[1], curr.normal[2]);
    v_gd.next_normal = vec3(next.normal[0], next.normal[1], next.normal[2]);

    v_gd.prev_data = bool(prev.data);
    v_gd.curr_data = bool(curr.data);
    v_gd.next_data = bool(next.data);
}

#type geometry
#version 430 core
layout (points) in;
layout (triangle_strip, max_vertices = 24) out;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
uniform vec3 u_camera_position;
uniform bool u_follow;

in geometry_data {
    vec3 prev_pos;
    vec3 next_pos;

    float curr_size;
    float next_size;

    vec3 curr_normal;
    vec3 next_normal;

    bool prev_data;
    bool curr_data;
    bool next_data;
} v_gd[];

const float HALF_PI = 1.57079632679;

void swap(inout vec3 a, inout vec3 b) {
    vec3 temp = a;
    a = b;
    b = temp;
}

void main() {
    vec3 prev_pos = v_gd[0].prev_pos;
    vec3 curr_pos = gl_in[0].gl_Position.xyz;
    vec3 next_pos = v_gd[0].next_pos;

    float curr_size = v_gd[0].curr_size;
    float next_size = v_gd[0].next_size;

    vec3 curr_normal = v_gd[0].curr_normal;
    vec3 next_normal = v_gd[0].next_normal;

    bool prev_data = v_gd[0].prev_data;
    bool curr_data = v_gd[0].curr_data;
    bool next_data = v_gd[0].next_data;

    mat4 pvm = u_projection * u_view; // * u_model;

    vec3 prev_line_dir = normalize(curr_pos - prev_pos);
    vec3 curr_line_dir = normalize(next_pos - curr_pos);

    vec3 prev_line_mid = (prev_pos + curr_pos) / 2.0;
    vec3 curr_line_mid = (curr_pos + next_pos) / 2.0;

    vec3 prev_perp = normalize(cross(prev_line_dir, vec3(0.0, 0.0, 1.0)));
    vec3 curr_perp = normalize(cross(curr_line_dir, vec3(0.0, 0.0, 1.0)));

    bool should_draw_line = curr_data;
    bool should_draw_start_cap = !prev_data && curr_data;
    bool should_draw_end_cap = prev_data && !curr_data;
    bool should_draw_cap = should_draw_start_cap || should_draw_end_cap;
    bool should_draw_join = prev_data && curr_data;

    if (should_draw_line) {
        vec3 perp1 = curr_perp * curr_size;
        vec3 perp2 = curr_perp * next_size;

        gl_Position = pvm * vec4(curr_pos - perp1, 1.0);
        EmitVertex();

        gl_Position = pvm * vec4(curr_pos + perp1, 1.0);
        EmitVertex();

        gl_Position = pvm * vec4(next_pos - perp2, 1.0);
        EmitVertex();

        gl_Position = pvm * vec4(next_pos + perp2, 1.0);
        EmitVertex();

        EndPrimitive();
    }

    // Cap
    if (should_draw_cap) {
        float dir = should_draw_start_cap ? -1.0 : 1.0;
        vec3 perp = (should_draw_start_cap ? curr_perp : prev_perp) * curr_size * dir;
        vec3 line_dir = (should_draw_start_cap ? curr_line_dir : prev_line_dir) * curr_size * dir;

        // Triangle
        {
            // gl_Position = pvm * vec4(curr_pos - perp, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + perp, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + line_dir, 1.0);
            // EmitVertex();

            // EndPrimitive();
        }

        // Square
        {
            // gl_Position = pvm * vec4(curr_pos - perp, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + perp, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos - perp + line_dir, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + perp + line_dir, 1.0);
            // EmitVertex();

            // EndPrimitive();
        }

        // Round
        {
            // gl_Position = pvm * vec4(curr_pos - perp, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + perp, 1.0);
            // EmitVertex();

            // int sub = 3;
            // float angle = HALF_PI / sub;

            // for (int i = 1; i < sub; ++i) {
            //     float x = cos(angle * i);
            //     float y = sin(angle * i);

            //     gl_Position = pvm * vec4(curr_pos - perp * x + line_dir * y, 1.0);
            //     EmitVertex();

            //     gl_Position = pvm * vec4(curr_pos + perp * x + line_dir * y, 1.0);
            //     EmitVertex();
            // }

            // gl_Position = pvm * vec4(curr_pos + line_dir, 1.0);
            // EmitVertex();
        }
    }

    // Join
    if (should_draw_join) {
        float dir = sign(dot(prev_line_dir, curr_perp));
        vec3 p1 = curr_pos + prev_perp * curr_size * dir;
        vec3 p2 = curr_pos + curr_perp * curr_size * dir;

        if (dir < 0.0) {
            swap(p1, p2);
        }

        // Bevel
        {
            // gl_Position = pvm * vec4(curr_pos, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p1, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p2, 1.0);
            // EmitVertex();

            // EndPrimitive();
        }

        // Miter
        {
            // vec3 miter_normal = normalize(prev_line_dir - curr_line_dir);
            // vec3 k = normalize(p1 - p2);
            // float d = dot(k, curr_line_dir);
            // float l = min(curr_size / d, 1.0);
            // vec3 mitter = curr_pos + miter_normal * l * -dir;

            // gl_Position = pvm * vec4(curr_pos, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p1, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p2, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(mitter, 1.0);
            // EmitVertex();

            // EndPrimitive();
        }

        // Round
        {
            // vec3 p1 = curr_pos + prev_perp * curr_size * dir;
            // vec3 p2 = curr_pos + curr_perp * curr_size * dir;
            // vec3 miter_normal = normalize(prev_line_dir - curr_line_dir);

            // gl_Position = pvm * vec4(curr_pos, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p1, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(p2, 1.0);
            // EmitVertex();

            // gl_Position = pvm * vec4(curr_pos + miter_normal * curr_size, 1.0);
            // EmitVertex();

            // EndPrimitive();
        }
    }
}

#type fragment
#version 430 core
precision mediump float;
in vec3 v_color;
out vec4 o_frag_color;

void main() {
    o_frag_color = vec4(vec3(1.0), 1.0);
}
