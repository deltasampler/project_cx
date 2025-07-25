// basic
void vec2_abs(vec2_t& out, const vec2_t& v);
vec2_t vec2n_abs(const vec2_t& out);
void vec2m_abs(vec2_t& out);

void vec2_neg(vec2_t& out, const vec2_t& v);
vec2_t vec2n_neg(const vec2_t& out);
void vec2m_neg(vec2_t& out);

void vec2_inv(vec2_t& out, const vec2_t& v);
vec2_t vec2n_inv(const vec2_t& out);
void vec2m_inv(vec2_t& out);

// product
num_t vec2_dot(const vec2_t& v0, const vec2_t& v1);

num_t vec2_cross(const vec2_t& v0, const vec2_t& v1);

// norm
num_t vec2_len(const vec2_t& v);
num_t vec2_len_sq(const vec2_t& v);

num_t vec2_dist(const vec2_t& v0, const vec2_t& v1);
num_t vec2_dist_sq(const vec2_t& v0, const vec2_t& v1);

void vec2_unit(vec2_t& out, const vec2_t& v);
vec2_t vec2n_unit(const vec2_t& v);
void vec2m_unit(vec2_t& out);

void vec2_dir(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_dir(vec2_t& v0, const vec2_t& v1);

// interpolation
void vec2_lerp(vec2_t& out, const vec2_t& v0, const vec2_t& v1, num_t t);
vec2_t vec2n_lerp(const vec2_t& v0, const vec2_t& v1, num_t t);
void vec2m_lerp(vec2_t& out, const vec2_t& v, num_t t);

// geometric
void vec2_refl(vec2_t& out, const vec2_t& v, const vec2_t& n);
vec2_t vec2n_refl(const vec2_t& v, const vec2_t& n);

void vec2_perp(vec2_t& out, const vec2_t& v);
vec2_t vec2n_perp(const vec2_t& v);

// rotation
void vec2_rotate(vec2_t& out, const vec2_t& v, num_t r, const vec2_t& p = {num_t(0.0), num_t(0.0)});
vec2_t vec2n_rotate(const vec2_t& v, num_t r, const vec2_t& p = {num_t(0.0), num_t(0.0)});
void vec2m_rotate(vec2_t& out, num_t r, const vec2_t& p = {num_t(0.0), num_t(0.0)});

// rounding
void vec2_trunc(vec2_t& out, const vec2_t& v);
vec2_t vec2n_trunc(const vec2_t& v);
void vec2m_trunc(vec2_t& out);

void vec2_floor(vec2_t& out, const vec2_t& v);
vec2_t vec2n_floor(const vec2_t& v);
void vec2m_floor(vec2_t& out);

void vec2_ceil(vec2_t& out, const vec2_t& v);
vec2_t vec2n_ceil(const vec2_t& v);
void vec2m_ceil(vec2_t& out);

void vec2_round(vec2_t& out, const vec2_t& v);
vec2_t vec2n_round(const vec2_t& v);
void vec2m_round(vec2_t& out);

void vec2_snap(vec2_t& out, const vec2_t& v, const vec2_t c);
vec2_t vec2n_snap(const vec2_t& v, const vec2_t c);
void vec2m_snap(vec2_t& out, const vec2_t c);

// comparison
bool vec2_equals(const vec2_t& v0, const vec2_t& v1, num_t e = num_t(0.000001));
