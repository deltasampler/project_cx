// arithmetic - matrix x matrix
void mat3_add(mat3_t& out, const mat3_t& m0, const mat3_t& m1);
mat3_t mat3n_add(const mat3_t& m0, const mat3_t& m1);
void mat3m_add(mat3_t& out, const mat3_t& m);

void mat3_sub(mat3_t& out, const mat3_t& m0, const mat3_t& m1);
mat3_t mat3n_sub(const mat3_t& m0, const mat3_t& m1);
void mat3m_sub(mat3_t& out, const mat3_t& m);

// arithmetic - matrix x scalar
void mat3_muls(mat3_t& out, const mat3_t& m, num_t s);
mat3_t mat3n_muls(const mat3_t& m, num_t s);
void mat3m_muls(mat3_t& out, num_t s);

// arithmetic - matrix x matrix x scalar
void mat3_addmuls(mat3_t& out, const mat3_t& m0, const mat3_t& m1, num_t s);
mat3_t mat3n_addmuls(const mat3_t& m0, const mat3_t& m1, num_t s);
void mat3m_addmuls(mat3_t& out, const mat3_t& m, num_t s);

// product - matrix x matrix
void mat3_mul(mat3_t& out, const mat3_t& m0, const mat3_t& m1);
mat3_t mat3n_mul(const mat3_t& m0, const mat3_t& m1);
void mat3m_mul(mat3_t& out, const mat3_t& m);

// product - matrix x vector
void mat3_mulmv(vec3_t& out, const vec3_t& v, const mat3_t& m);
vec3_t mat3n_mulmv(const vec3_t& v, const mat3_t& m);
void mat3m_mulmv(vec3_t& out, const mat3_t& m);

void mat3_mulvm(vec3_t& out, const vec3_t& v, const mat3_t& m);
vec3_t mat3n_mulvm(const vec3_t& v, const mat3_t& m);
void mat3m_mulvm(vec3_t& out, const mat3_t& m);

// string
void mat3_str(const mat3_t& m, char* str);
void mat3_print(const mat3_t& m);

// arithmetic operator overloading - matrix x matrix
mat3_t operator+(const mat3_t& m0, const mat3_t& m1);
mat3_t& operator+=(mat3_t& out, const mat3_t& m);

mat3_t operator-(const mat3_t& m0, const mat3_t& m1);
mat3_t& operator-=(mat3_t& out, const mat3_t& m);

// arithmetic operator overloading - matrix x scalar
mat3_t operator*(const mat3_t& m, num_t s);
mat3_t& operator*=(mat3_t& out, num_t s);

// product operator overloading - matrix x matrix
mat3_t operator*(const mat3_t& m0, const mat3_t& m1);
mat3_t& operator*=(mat3_t& out, const mat3_t& m);

// product operator overloading - matrix x vector
vec3_t operator*(const mat3_t& m, const vec3_t& v);

vec3_t operator*(const vec3_t& v, const mat3_t& m);
vec3_t& operator*=(vec3_t& out, const mat3_t& m);
