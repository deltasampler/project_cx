// special
num_t mat4_det(const mat4_t& m);
num_t mat4_frob(const mat4_t& m);

void mat4_transp(mat4_t& out, const mat4_t& m);
mat4_t mat4n_transp(const mat4_t& m);
void mat4m_transp(mat4_t& out);

void mat4_adjoint(mat4_t& out, const mat4_t& m);
mat4_t mat4n_adjoint(const mat4_t& m);
void mat4m_adjoint(mat4_t& out);

void mat4_inv(mat4_t& out, const mat4_t& m);
mat4_t mat4n_inv(const mat4_t& m);
void mat4m_inv(mat4_t& out);

// comparison
bool mat4_equals(const mat4_t& v0, const mat4_t& v1, num_t e = num_t(0.000001));
