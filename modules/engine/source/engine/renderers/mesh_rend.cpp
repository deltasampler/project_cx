#include <glad/gl.h>
#include <gl/shader.h>

#ifndef MODULE_PATH
#define MODULE_PATH "./"
#endif

#include "mesh_rend.h"

static struct {
    u32 handle = 0;
    s32 i_color = 0;
    s32 u_projection = 0;
    s32 u_view = 0;
    s32 u_cam_pos = 0;
    s32 u_color = 0;
    s32 u_sun_direction = 0;
    s32 u_sun_color = 0;
} program;

void mesh_rdata_new(mesh_rdata_t& rdata) {
    rdata.vao = 0;
    rdata.vbo = 0;
    rdata.ebo = 0;
}

void mesh_rdata_build(mesh_rdata_t& rdata) {
    if (rdata.vao == 0) {
        glGenVertexArrays(1, &rdata.vao);
    }

    glBindVertexArray(rdata.vao);

    if (rdata.vbo == 0) {
        glGenBuffers(1, &rdata.vbo);
    }

    glBindBuffer(GL_ARRAY_BUFFER, rdata.vbo);
    glBufferData(GL_ARRAY_BUFFER, rdata.vertices.cap * sizeof(vertex_t), rdata.vertices.data, GL_DYNAMIC_DRAW);

    s32 offset = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)(offset));
    glEnableVertexAttribArray(0);

    offset += sizeof(vec3_t);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)(offset));
    glEnableVertexAttribArray(1);

    offset += sizeof(vec3_t);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)(offset));
    glEnableVertexAttribArray(2);

    offset += sizeof(fvec2_t);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)(offset));
    glEnableVertexAttribArray(3);

    if (rdata.ebo == 0) {
        glGenBuffers(1, &rdata.ebo);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rdata.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, rdata.indices.cap * sizeof(u32), rdata.indices.data, GL_STATIC_DRAW);
}

void mesh_rdata_clear(mesh_rdata_t& rdata) {
    darr_del(rdata.vertices);
    darr_del(rdata.indices);
    glDeleteVertexArrays(1, &rdata.vao);
    glDeleteBuffers(1, &rdata.vbo);
    glDeleteBuffers(1, &rdata.ebo);
}

void mesh_rend_init() {
    program.handle = program_load(MODULE_PATH"assets/shaders/mesh_rend.glsl");
    program.u_projection = glGetUniformLocation(program.handle, "u_projection");
    program.u_view = glGetUniformLocation(program.handle, "u_view");
    program.u_cam_pos = glGetUniformLocation(program.handle, "u_cam_pos");
    program.u_color = glGetUniformLocation(program.handle, "u_color");
    program.u_sun_direction = glGetUniformLocation(program.handle, "u_sun_direction");
    program.u_sun_color = glGetUniformLocation(program.handle, "u_sun_color");
}

void mesh_rend_shut() {
    glDeleteProgram(program.handle);
}

void mesh_rend_render(mesh_rdata_t& rdata, const cam3_t& cam, const sky_rdata_t& sky_rdata) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glUseProgram(program.handle);
    glUniformMatrix4fv(program.u_projection, 1, false, cam.projection.arr);
    glUniformMatrix4fv(program.u_view, 1, false, cam.view.arr);
    glUniform3fv(program.u_cam_pos, 1, cam.position.arr);
    glUniform3fv(program.u_sun_direction, 1, sky_rdata.sun_direction.arr);
    glUniform3fv(program.u_sun_color, 1, sky_rdata.sun_color.arr);

    glBindVertexArray(rdata.vao);
    glDrawElements(GL_TRIANGLES, rdata.indices.len, GL_UNSIGNED_INT, 0);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
