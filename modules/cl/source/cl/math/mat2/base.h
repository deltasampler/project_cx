// arithmetic - matrix x matrix
void mat2_add(mat2_t& out, const mat2_t& m0, const mat2_t& m1);
mat2_t mat2n_add(const mat2_t& m0, const mat2_t& m1);
void mat2m_add(mat2_t& out, const mat2_t& m);

void mat2_sub(mat2_t& out, const mat2_t& m0, const mat2_t& m1);
mat2_t mat2n_sub(const mat2_t& m0, const mat2_t& m1);
void mat2m_sub(mat2_t& out, const mat2_t& m);

// arithmetic - matrix x scalar
void mat2_muls(mat2_t& out, const mat2_t& m, num_t s);
mat2_t mat2n_muls(const mat2_t& m, num_t s);
void mat2m_muls(mat2_t& out, num_t s);

// arithmetic - matrix x matrix x scalar
void mat2_addmuls(mat2_t& out, const mat2_t& m0, const mat2_t& m1, num_t s);
mat2_t mat2n_addmuls(const mat2_t& m0, const mat2_t& m1, num_t s);
void mat2m_addmuls(mat2_t& out, const mat2_t& m, num_t s);

// product - matrix x matrix
void mat2_mul(mat2_t& out, const mat2_t& m0, const mat2_t& m1);
mat2_t mat2n_mul(const mat2_t& m0, const mat2_t& m1);
void mat2m_mul(mat2_t& out, const mat2_t& m);

// product - matrix x vector
void mat2_mulmv(vec2_t& out, const vec2_t& v, const mat2_t& m);
vec2_t mat2n_mulmv(const vec2_t& v, const mat2_t& m);
void mat2m_mulmv(vec2_t& out, const mat2_t& m);

void mat2_mulvm(vec2_t& out, const vec2_t& v, const mat2_t& m);
vec2_t mat2n_mulvm(const vec2_t& v, const mat2_t& m);
void mat2m_mulvm(vec2_t& out, const mat2_t& m);

// string
void mat2_str(const mat2_t& m, char* str);
void mat2_print(const mat2_t& m);

// arithmetic operator overloading - matrix x matrix
mat2_t operator+(const mat2_t& m0, const mat2_t& m1);
mat2_t& operator+=(mat2_t& out, const mat2_t& m);

mat2_t operator-(const mat2_t& m0, const mat2_t& m1);
mat2_t& operator-=(mat2_t& out, const mat2_t& m);

// arithmetic operator overloading - matrix x scalar
mat2_t operator*(const mat2_t& m, num_t s);
mat2_t& operator*=(mat2_t& out, num_t s);

// product operator overloading - matrix x matrix
mat2_t operator*(const mat2_t& m0, const mat2_t& m1);
mat2_t& operator*=(mat2_t& out, const mat2_t& m);

// product operator overloading - matrix x vector
vec2_t operator*(const mat2_t& m, const vec2_t& v);

vec2_t operator*(const vec2_t& v, const mat2_t& m);
vec2_t& operator*=(vec2_t& out, const mat2_t& m);
