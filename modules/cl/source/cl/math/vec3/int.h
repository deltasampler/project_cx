// packing
num_t vec3_pack(const vec3_t& v);

void vec3_unpack(vec3_t& out, num_t x);
vec3_t vec3n_unpack(num_t x);

// comparison
bool vec3_equals(const vec3_t& v0, const vec3_t& v1);
