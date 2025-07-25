// basic
void vec3_abs(vec3_t& out, const vec3_t& v);
vec3_t vec3n_abs(const vec3_t& out);
void vec3m_abs(vec3_t& out);

void vec3_neg(vec3_t& out, const vec3_t& v);
vec3_t vec3n_neg(const vec3_t& out);
void vec3m_neg(vec3_t& out);

void vec3_inv(vec3_t& out, const vec3_t& v);
vec3_t vec3n_inv(const vec3_t& out);
void vec3m_inv(vec3_t& out);

// product
num_t vec3_dot(const vec3_t& v0, const vec3_t& v1);

void vec3_cross(vec3_t& out, const vec3_t& v0, const vec3_t& v1);
vec3_t vec3n_cross(const vec3_t& v0, const vec3_t& v1);

// norm
num_t vec3_len(const vec3_t& v);
num_t vec3_len_sq(const vec3_t& v);

num_t vec3_dist(const vec3_t& v0, const vec3_t& v1);
num_t vec3_dist_sq(const vec3_t& v0, const vec3_t& v1);

void vec3_unit(vec3_t& out, const vec3_t& v);
vec3_t vec3n_unit(const vec3_t& v);
void vec3m_unit(vec3_t& out);

void vec3_dir(vec3_t& out, const vec3_t& v0, const vec3_t& v1);
vec3_t vec3n_dir(vec3_t& v0, const vec3_t& v1);

// interpolation
void vec3_lerp(vec3_t& out, const vec3_t& v0, const vec3_t& v1, num_t t);
vec3_t vec3n_lerp(const vec3_t& v0, const vec3_t& v1, num_t t);
void vec3m_lerp(vec3_t& out, const vec3_t& v, num_t t);

// geometric
void vec3_refl(vec3_t& out, const vec3_t& v, const vec3_t& n);
vec3_t vec3n_refl(const vec3_t& v, const vec3_t& n);

// rotation
void vec3_rotate_x(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
vec3_t vec3n_rotate_x(const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
void vec3m_rotate_x(vec3_t& out, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});

void vec3_rotate_y(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
vec3_t vec3n_rotate_y(const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
void vec3m_rotate_y(vec3_t& out, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});

void vec3_rotate_z(vec3_t& out, const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
vec3_t vec3n_rotate_z(const vec3_t& v, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});
void vec3m_rotate_z(vec3_t& out, num_t r, const vec3_t& p = {num_t(0.0), num_t(0.0), num_t(0.0)});

// rounding
void vec3_trunc(vec3_t& out, const vec3_t& v);
vec3_t vec3n_trunc(const vec3_t& v);
void vec3m_trunc(vec3_t& out);

void vec3_floor(vec3_t& out, const vec3_t& v);
vec3_t vec3n_floor(const vec3_t& v);
void vec3m_floor(vec3_t& out);

void vec3_ceil(vec3_t& out, const vec3_t& v);
vec3_t vec3n_ceil(const vec3_t& v);
void vec3m_ceil(vec3_t& out);

void vec3_round(vec3_t& out, const vec3_t& v);
vec3_t vec3n_round(const vec3_t& v);
void vec3m_round(vec3_t& out);

void vec3_snap(vec3_t& out, const vec3_t& v, const vec3_t c);
vec3_t vec3n_snap(const vec3_t& v, const vec3_t c);
void vec3m_snap(vec3_t& out, const vec3_t c);

// comparison
bool vec3_equals(const vec3_t& v0, const vec3_t& v1, num_t e = num_t(0.000001));
