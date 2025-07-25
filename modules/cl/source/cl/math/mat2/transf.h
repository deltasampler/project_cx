// affine
void mat2_rotation(mat2_t& out, num_t r);
mat2_t mat2n_rotation(num_t r);

void mat2_scaling(mat2_t& out, const vec2_t& v);
mat2_t mat2n_scaling(const vec2_t& v);

void mat2_rotate(mat2_t& out, const mat2_t& m, num_t r);
mat2_t mat2n_rotate(const mat2_t& m, num_t r);
void mat2m_rotate(mat2_t& out, num_t r);

void mat2_scale(mat2_t& out, const mat2_t& m, const vec2_t& v);
mat2_t mat2n_scale(const mat2_t& m, const vec2_t& v);
void mat2m_scale(mat2_t& out, const vec2_t& v);
