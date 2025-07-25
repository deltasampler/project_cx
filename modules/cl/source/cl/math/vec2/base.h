// arithmetic - vector x vector
void vec2_add(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_add(const vec2_t& v0, const vec2_t& v1);
void vec2m_add(vec2_t& out, const vec2_t& v);

void vec2_sub(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_sub(const vec2_t& v0, const vec2_t& v1);
void vec2m_sub(vec2_t& out, const vec2_t& v);

void vec2_mul(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_mul(const vec2_t& v0, const vec2_t& v1);
void vec2m_mul(vec2_t& out, const vec2_t& v);

void vec2_div(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_div(const vec2_t& v0, const vec2_t& v1);
void vec2m_div(vec2_t& out, const vec2_t& v);

// arithmetic - vector x scalar
void vec2_adds(vec2_t& out, const vec2_t& v, num_t s);
vec2_t vec2n_adds(const vec2_t& v, num_t s);
void vec2m_adds(vec2_t& out, num_t s);

void vec2_subs(vec2_t& out, const vec2_t& v, num_t s);
vec2_t vec2n_subs(const vec2_t& v, num_t s);
void vec2m_subs(vec2_t& out, num_t s);

void vec2_muls(vec2_t& out, const vec2_t& v, num_t s);
vec2_t vec2n_muls(const vec2_t& v, num_t s);
void vec2m_muls(vec2_t& out, num_t s);

void vec2_divs(vec2_t& out, const vec2_t& v, num_t s);
vec2_t vec2n_divs(const vec2_t& v, num_t s);
void vec2m_divs(vec2_t& out, num_t s);

// arithmetic - vector x vector x scalar
void vec2_addmuls(vec2_t& out, const vec2_t& v0, const vec2_t& v1, num_t s);
vec2_t vec2n_addmuls(const vec2_t& v0, const vec2_t& v1, num_t s);
void vec2m_addmuls(vec2_t& out, const vec2_t& v, num_t s);

// bounding
void vec2_min(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_min(const vec2_t& v0, const vec2_t& v1);

void vec2_max(vec2_t& out, const vec2_t& v0, const vec2_t& v1);
vec2_t vec2n_max(const vec2_t& v0, const vec2_t& v1);

void vec2_clamp(vec2_t& out, const vec2_t& v, const vec2_t& min, const vec2_t& max);
vec2_t vec2n_clamp(const vec2_t& v, const vec2_t& min, const vec2_t& max);
void vec2m_clamp(vec2_t& out, const vec2_t& min, const vec2_t& max);

// string
void vec2_str(const vec2_t& v, char* str);
void vec2_print(const vec2_t& v);

// arithmetic - operator overloading - vector x vector
vec2_t operator+(const vec2_t& v0, const vec2_t& v1);
vec2_t& operator+=(vec2_t& out, const vec2_t& v);

vec2_t operator-(const vec2_t& v0, const vec2_t& v1);
vec2_t& operator-=(vec2_t& out, const vec2_t& v);

vec2_t operator*(const vec2_t& v0, const vec2_t& v1);
vec2_t& operator*=(vec2_t& out, const vec2_t& v);

vec2_t operator/(const vec2_t& v0, const vec2_t& v1);
vec2_t& operator/=(vec2_t& out, const vec2_t& v);

// arithmetic - operator overloading - vector x scalar
vec2_t operator+(const vec2_t& v, num_t s);
vec2_t& operator+=(vec2_t& out, num_t s);

vec2_t operator-(const vec2_t& v, num_t s);
vec2_t& operator-=(vec2_t& out, num_t s);

vec2_t operator*(const vec2_t& v, num_t s);
vec2_t& operator*=(vec2_t& out, num_t s);

vec2_t operator/(const vec2_t& v, num_t s);
vec2_t& operator/=(vec2_t& out, num_t s);
