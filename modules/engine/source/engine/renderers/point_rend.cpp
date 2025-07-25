#include <glad/gl.h>
#include <gl/shader.h>

#ifndef MODULE_PATH
#define MODULE_PATH "./"
#endif

#include "point_rend.h"

static struct {
    u32 handle = 0;
    s32 u_projection = 0;
    s32 u_view = 0;
    s32 u_camera_up = 0;
    s32 u_camera_right = 0;
} program;

void point_rdata_new(point_rdata_t& rdata) {
    rdata.vao = 0;
    rdata.vbo= 0;
}

void point_rdata_build(point_rdata_t& rdata) {
    if (rdata.vao == 0) {
        glGenVertexArrays(1, &rdata.vao);
    }

    glBindVertexArray(rdata.vao);

    if (rdata.vbo == 0) {
        glGenBuffers(1, &rdata.vbo);
    }

    glBindBuffer(GL_ARRAY_BUFFER, rdata.vbo);
    glBufferData(GL_ARRAY_BUFFER, rdata.points.cap * sizeof(point_t), rdata.points.data, GL_DYNAMIC_DRAW);

    s32 offset = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(point_t), (void*)(offset));
    glEnableVertexAttribArray(0);

    offset += sizeof(fvec3_t);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(point_t), (void*)(offset));
    glEnableVertexAttribArray(1);

    offset += sizeof(f32);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(point_t), (void*)(offset));
    glEnableVertexAttribArray(2);
}

void point_rdata_clear(point_rdata_t& rdata) {
    darr_del(rdata.points);
    glDeleteVertexArrays(1, &rdata.vao);
    glDeleteBuffers(1, &rdata.vbo);
}

void point_rend_init() {
    program.handle = program_load(MODULE_PATH"assets/shaders/point_rend.glsl");
    program.u_projection = glGetUniformLocation(program.handle, "u_projection");
    program.u_view = glGetUniformLocation(program.handle, "u_view");
    program.u_camera_right = glGetUniformLocation(program.handle, "u_camera_right");
    program.u_camera_up = glGetUniformLocation(program.handle, "u_camera_up");
}

void point_rend_shut() {
    glDeleteProgram(program.handle);
}

void point_rend_render(point_rdata_t& rdata, const cam3_t& cam) {
    glUseProgram(program.handle);
    glUniformMatrix4fv(program.u_projection, 1, false, cam.projection.arr);
    glUniformMatrix4fv(program.u_view, 1, false, cam.view.arr);
    glUniform3fv(program.u_camera_right, 1, cam.right.arr);
    glUniform3fv(program.u_camera_up, 1, cam.up.arr);

    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(rdata.vao);
    glDrawArrays(GL_POINTS, 0, rdata.points.len);
    glDisable(GL_DEPTH_TEST);
}
