// arithmetic - matrix x matrix
void mat4_add(mat4_t& out, const mat4_t& m0, const mat4_t& m1);
mat4_t mat4n_add(const mat4_t& m0, const mat4_t& m1);
void mat4m_add(mat4_t& out, const mat4_t& m);

void mat4_sub(mat4_t& out, const mat4_t& m0, const mat4_t& m1);
mat4_t mat4n_sub(const mat4_t& m0, const mat4_t& m1);
void mat4m_sub(mat4_t& out, const mat4_t& m);

// arithmetic - matrix x scalar
void mat4_muls(mat4_t& out, const mat4_t& m, num_t s);
mat4_t mat4n_muls(const mat4_t& m, num_t s);
void mat4m_muls(mat4_t& out, num_t s);

// arithmetic - matrix x matrix x scalar
void mat4_addmuls(mat4_t& out, const mat4_t& m0, const mat4_t& m1, num_t s);
mat4_t mat4n_addmuls(const mat4_t& m0, const mat4_t& m1, num_t s);
void mat4m_addmuls(mat4_t& out, const mat4_t& m, num_t s);

// product - matrix x matrix
void mat4_mul(mat4_t& out, const mat4_t& m0, const mat4_t& m1);
mat4_t mat4n_mul(const mat4_t& m0, const mat4_t& m1);
void mat4m_mul(mat4_t& out, const mat4_t& m);

// product - matrix x vector
void mat4_mulmv(vec4_t& out, const vec4_t& v, const mat4_t& m);
vec4_t mat4n_mulmv(const vec4_t& v, const mat4_t& m);
void mat4m_mulmv(vec4_t& out, const mat4_t& m);

void mat4_mulvm(vec4_t& out, const vec4_t& v, const mat4_t& m);
vec4_t mat4n_mulvm(const vec4_t& v, const mat4_t& m);
void mat4m_mulvm(vec4_t& out, const mat4_t& m);

// string
void mat4_str(const mat4_t& m, char* str);
void mat4_print(const mat4_t& m);

// arithmetic operator overloading - matrix x matrix
mat4_t operator+(const mat4_t& m0, const mat4_t& m1);
mat4_t& operator+=(mat4_t& out, const mat4_t& m);

mat4_t operator-(const mat4_t& m0, const mat4_t& m1);
mat4_t& operator-=(mat4_t& out, const mat4_t& m);

// arithmetic operator overloading - matrix x scalar
mat4_t operator*(const mat4_t& m, num_t s);
mat4_t& operator*=(mat4_t& out, num_t s);

// product operator overloading - matrix x matrix
mat4_t operator*(const mat4_t& m0, const mat4_t& m1);
mat4_t& operator*=(mat4_t& out, const mat4_t& m);

// product operator overloading - matrix x vector
vec4_t operator*(const mat4_t& m, const vec4_t& v);

vec4_t operator*(const vec4_t& v, const mat4_t& m);
vec4_t& operator*=(vec4_t& out, const mat4_t& m);
