// affine
void mat4_translation(mat4_t& out, const vec3_t& v);
mat4_t mat4n_translation(const vec3_t& v);

void mat4_rotation(mat4_t& out, num_t r, const vec3_t& axis);
mat4_t mat4n_rotation(num_t r, const vec3_t& axis);

void mat4_rotation_x(mat4_t& out, num_t r);
mat4_t mat4n_rotation_x(num_t r);

void mat4_rotation_y(mat4_t& out, num_t r);
mat4_t mat4n_rotation_y(num_t r);

void mat4_rotation_z(mat4_t& out, num_t r);
mat4_t mat4n_rotation_z(num_t r);

void mat4_scaling(mat4_t& out, const vec3_t& v);
mat4_t mat4n_scaling(const vec3_t& v);

void mat4_translate(mat4_t& out, const mat4_t& m, const vec3_t& v);
mat4_t mat4n_translate(const mat4_t& m, const vec3_t& v);
void mat4m_translate(mat4_t& out, const vec3_t& v);

void mat4_rotate(mat4_t& out, const mat4_t& m, num_t r, const vec3_t& axis);
mat4_t mat4n_rotate(const mat4_t& m, num_t r, const vec3_t& axis);
void mat4m_rotate(mat4_t& out, num_t r, const vec3_t& axis);

void mat4_rotate_x(mat4_t& out, const mat4_t& m, num_t r);
mat4_t mat4n_rotate_x(const mat4_t& m, num_t r);
void mat4m_rotate_x(mat4_t& out, num_t r);

void mat4_rotate_y(mat4_t& out, const mat4_t& m, num_t r);
mat4_t mat4n_rotate_y(const mat4_t& m, num_t r);
void mat4m_rotate_y(mat4_t& out, num_t r);

void mat4_rotate_z(mat4_t& out, const mat4_t& m, num_t r);
mat4_t mat4n_rotate_z(const mat4_t& m, num_t r);
void mat4m_rotate_z(mat4_t& out, num_t r);

void mat4_scale(mat4_t& out, const mat4_t& m, const vec3_t& v);
mat4_t mat4n_scale(const mat4_t& m, const vec3_t& v);
void mat4m_scale(mat4_t& out, const vec3_t& v);

// projection
void mat4_perspective(mat4_t& out, num_t fov, num_t aspect, num_t near, num_t far);
mat4_t mat4n_perspective(num_t fov, num_t aspect, num_t near, num_t far);

// camera
void mat4_look_at(mat4_t& out, const vec3_t& eye, const vec3_t& center, const vec3_t& up);
mat4_t mat4n_look_at(const vec3_t& eye, const vec3_t& center, const vec3_t& up);

void mat4_target_to(mat4_t& out, const vec3_t& eye, const vec3_t& target, const vec3_t& up);
mat4_t mat4n_target_to(const vec3_t& eye, const vec3_t& target, const vec3_t& up);
