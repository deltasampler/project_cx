#include <glad/gl.h>
#include <gl/shader.h>

#ifndef MODULE_PATH
#define MODULE_PATH "./"
#endif

#include "line2_rend.h"

static struct {
    u32 handle = 0;
    s32 u_projection = 0;
    s32 u_view = 0;
    s32 u_camera_position = 0;
    s32 u_should_follow = 0;
} program;

void line2_rdata_new(line2_rdata_t& rdata) {
    rdata.should_follow = false;
    rdata.vao = 0;
    rdata.vbo = 0;
}

void line2_rdata_build(line2_rdata_t& rdata) {
    if (rdata.vao == 0) {
        glGenVertexArrays(1, &rdata.vao);
    }

    glBindVertexArray(rdata.vao);

    if (rdata.vbo == 0) {
        glGenBuffers(1, &rdata.vbo);
    }

    glBindBuffer(GL_ARRAY_BUFFER, rdata.vbo);
    glBufferData(GL_ARRAY_BUFFER, rdata.points.len * sizeof(line2_point_t), rdata.points.data, GL_DYNAMIC_DRAW);

    s32 offset = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(line2_point_t), (void*)(offset));
    glEnableVertexAttribArray(0);

    offset += sizeof(fvec3_t);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(line2_point_t), (void*)(offset));
    glEnableVertexAttribArray(1);

    offset += sizeof(f32);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(line2_point_t), (void*)(offset));
    glEnableVertexAttribArray(2);

    offset += sizeof(fvec3_t);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(line2_point_t), (void*)(offset));
    glEnableVertexAttribArray(3);
}

void line2_rdata_clear(line2_rdata_t& rdata) {
    darr_del(rdata.points);
    glDeleteVertexArrays(1, &rdata.vao);
    glDeleteBuffers(1, &rdata.vbo);
}

void line2_rend_init() {
    program.handle = program_load(MODULE_PATH"assets/shaders/line2_rend.glsl");
    program.u_projection = glGetUniformLocation(program.handle, "u_projection");
    program.u_view = glGetUniformLocation(program.handle, "u_view");
    program.u_camera_position = glGetUniformLocation(program.handle, "u_camera_position");
    program.u_should_follow = glGetUniformLocation(program.handle, "u_should_follow");
}

void line2_rend_shut() {
    glDeleteProgram(program.handle);
}

void line2_rend_render(line2_rdata_t& rdata, const cam3_t& cam) {
    glUseProgram(program.handle);
    glUniformMatrix4fv(program.u_projection, 1, false, cam.projection.arr);
    glUniformMatrix4fv(program.u_view, 1, false, cam.view.arr);
    glUniform3fv(program.u_camera_position, 1, cam.position.arr);
    glUniform1i(program.u_should_follow, rdata.should_follow);

    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(rdata.vao);
    glDrawArrays(GL_LINES, 0, rdata.points.len);
    glDisable(GL_DEPTH_TEST);
}
