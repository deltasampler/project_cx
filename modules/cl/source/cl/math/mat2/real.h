// special
num_t mat2_det(const mat2_t& m);
num_t mat2_frob(const mat2_t& m);

void mat2_transp(mat2_t& out, const mat2_t& m);
mat2_t mat2n_transp(const mat2_t& m);
void mat2m_transp(mat2_t& out);

void mat2_adjoint(mat2_t& out, const mat2_t& m);
mat2_t mat2n_adjoint(const mat2_t& m);
void mat2m_adjoint(mat2_t& out);

void mat2_inv(mat2_t& out, const mat2_t& m);
mat2_t mat2n_inv(const mat2_t& m);
void mat2m_inv(mat2_t& out);

// comparison
bool mat2_equals(const mat2_t& v0, const mat2_t& v1, num_t e = num_t(0.000001));
