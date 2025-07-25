// arithmetic - vector x vector
void vec4_add(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_add(const vec4_t& v0, const vec4_t& v1);
void vec4m_add(vec4_t& out, const vec4_t& v);

void vec4_sub(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_sub(const vec4_t& v0, const vec4_t& v1);
void vec4m_sub(vec4_t& out, const vec4_t& v);

void vec4_mul(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_mul(const vec4_t& v0, const vec4_t& v1);
void vec4m_mul(vec4_t& out, const vec4_t& v);

void vec4_div(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_div(const vec4_t& v0, const vec4_t& v1);
void vec4m_div(vec4_t& out, const vec4_t& v);

// arithmetic - vector x scalar
void vec4_adds(vec4_t& out, const vec4_t& v, num_t s);
vec4_t vec4n_adds(const vec4_t& v, num_t s);
void vec4m_adds(vec4_t& out, num_t s);

void vec4_subs(vec4_t& out, const vec4_t& v, num_t s);
vec4_t vec4n_subs(const vec4_t& v, num_t s);
void vec4m_subs(vec4_t& out, num_t s);

void vec4_muls(vec4_t& out, const vec4_t& v, num_t s);
vec4_t vec4n_muls(const vec4_t& v, num_t s);
void vec4m_muls(vec4_t& out, num_t s);

void vec4_divs(vec4_t& out, const vec4_t& v, num_t s);
vec4_t vec4n_divs(const vec4_t& v, num_t s);
void vec4m_divs(vec4_t& out, num_t s);

// arithmetic - vector x vector x scalar
void vec4_addmuls(vec4_t& out, const vec4_t& v0, const vec4_t& v1, num_t s);
vec4_t vec4n_addmuls(const vec4_t& v0, const vec4_t& v1, num_t s);
void vec4m_addmuls(vec4_t& out, const vec4_t& v, num_t s);

// bounding
void vec4_min(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_min(const vec4_t& v0, const vec4_t& v1);

void vec4_max(vec4_t& out, const vec4_t& v0, const vec4_t& v1);
vec4_t vec4n_max(const vec4_t& v0, const vec4_t& v1);

void vec4_clamp(vec4_t& out, const vec4_t& v, const vec4_t& min, const vec4_t& max);
vec4_t vec4n_clamp(const vec4_t& v, const vec4_t& min, const vec4_t& max);
void vec4m_clamp(vec4_t& out, const vec4_t& min, const vec4_t& max);

// string
void vec4_str(const vec4_t& v, char* str);
void vec4_print(const vec4_t& v);

// arithmetic - operator overloading - vector x vector
vec4_t operator+(const vec4_t& v0, const vec4_t& v1);
vec4_t& operator+=(vec4_t& out, const vec4_t& v);

vec4_t operator-(const vec4_t& v0, const vec4_t& v1);
vec4_t& operator-=(vec4_t& out, const vec4_t& v);

vec4_t operator*(const vec4_t& v0, const vec4_t& v1);
vec4_t& operator*=(vec4_t& out, const vec4_t& v);

vec4_t operator/(const vec4_t& v0, const vec4_t& v1);
vec4_t& operator/=(vec4_t& out, const vec4_t& v);

// arithmetic - operator overloading - vector x scalar
vec4_t operator+(const vec4_t& v, num_t s);
vec4_t& operator+=(vec4_t& out, num_t s);

vec4_t operator-(const vec4_t& v, num_t s);
vec4_t& operator-=(vec4_t& out, num_t s);

vec4_t operator*(const vec4_t& v, num_t s);
vec4_t& operator*=(vec4_t& out, num_t s);

vec4_t operator/(const vec4_t& v, num_t s);
vec4_t& operator/=(vec4_t& out, num_t s);
