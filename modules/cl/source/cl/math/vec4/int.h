// packing
num_t vec4_pack(const vec3_t& v);

void vec4_unpack(vec3_t& out, num_t x);
vec4_t vec4n_unpack(num_t x);

// comparison
bool vec4_equals(const vec4_t& v0, const vec4_t& v1);
