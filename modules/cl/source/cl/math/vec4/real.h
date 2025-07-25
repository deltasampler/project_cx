// basic
void vec4_abs(vec4_t& out, const vec4_t& v);
vec4_t vec4n_abs(const vec4_t& out);
void vec4m_abs(vec4_t& out);

void vec4_neg(vec4_t& out, const vec4_t& v);
vec4_t vec4n_neg(const vec4_t& out);
void vec4m_neg(vec4_t& out);

void vec4_inv(vec4_t& out, const vec4_t& v);
vec4_t vec4n_inv(const vec4_t& out);
void vec4m_inv(vec4_t& out);

// product
num_t vec4_dot(const vec4_t& v0, const vec4_t& v1);

// norm
num_t vec4_len(const vec4_t& v);
num_t vec4_len_sq(const vec4_t& v);

num_t vec4_dist(const vec4_t& v0, const vec4_t& v1);
num_t vec4_dist_sq(const vec4_t& v0, const vec4_t& v1);

void vec4_unit(vec4_t& out, const vec4_t& v);
vec4_t vec4n_unit(const vec4_t& v);
void vec4m_unit(vec4_t& out);

void vec4_dir(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_dir(vec4_t& v0, const vec4_t& v1);

// interpolation
void vec4_lerp(vec4_t& out, const vec4_t& v0, const vec4_t& v1, num_t t);
vec4_t vec4n_lerp(const vec4_t& v0, const vec4_t& v1, num_t t);
void vec4m_lerp(vec4_t& out, const vec4_t& v, num_t t);

// geometric
void vec4_refl(vec4_t& out, const vec4_t& v, const vec4_t& n);
vec4_t vec4n_refl(const vec4_t& v, const vec4_t& n);

// rounding
void vec4_trunc(vec4_t& out, const vec4_t& v);
vec4_t vec4n_trunc(const vec4_t& v);
void vec4m_trunc(vec4_t& out);

void vec4_floor(vec4_t& out, const vec4_t& v);
vec4_t vec4n_floor(const vec4_t& v);
void vec4m_floor(vec4_t& out);

void vec4_ceil(vec4_t& out, const vec4_t& v);
vec4_t vec4n_ceil(const vec4_t& v);
void vec4m_ceil(vec4_t& out);

void vec4_round(vec4_t& out, const vec4_t& v);
vec4_t vec4n_round(const vec4_t& v);
void vec4m_round(vec4_t& out);

void vec4_snap(vec4_t& out, const vec4_t& v, const vec4_t c);
vec4_t vec4n_snap(const vec4_t& v, const vec4_t c);
void vec4m_snap(vec4_t& out, const vec4_t c);

// comparison
bool vec4_equals(const vec4_t& v0, const vec4_t& v1, num_t e = num_t(0.000001));
