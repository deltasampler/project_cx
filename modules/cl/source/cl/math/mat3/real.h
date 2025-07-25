// special
num_t mat3_det(const mat3_t& m);
num_t mat3_frob(const mat3_t& m);

void mat3_transp(mat3_t& out, const mat3_t& m);
mat3_t mat3n_transp(const mat3_t& m);
void mat3m_transp(mat3_t& out);

void mat3_adjoint(mat3_t& out, const mat3_t& m);
mat3_t mat3n_adjoint(const mat3_t& m);
void mat3m_adjoint(mat3_t& out);

void mat3_inv(mat3_t& out, const mat3_t& m);
mat3_t mat3n_inv(const mat3_t& m);
void mat3m_inv(mat3_t& out);

// comparison
bool mat3_equals(const mat3_t& v0, const mat3_t& v1, num_t e = num_t(0.000001));
