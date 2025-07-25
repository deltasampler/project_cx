#undef vec3_t
#define vec3_t pre(vec3_t)

struct vec3_t {
    union {
        struct {
            num_t x;
            num_t y;
            num_t z;
        };
        num_t arr[3];
    };
};

// creation
vec3_t pre(vec3)(num_t x = num_t(0));
vec3_t pre(vec3)(num_t x, num_t y, num_t z);

void vec3_set(vec3_t& out, num_t x, num_t y, num_t z);

void vec3_zero(vec3_t& out);
vec3_t pre(vec3n_zero)();

void vec3_copy(vec3_t& out, const vec3_t& v);
vec3_t vec3n_copy(const vec3_t& v);
