#undef vec4_t
#define vec4_t pre(vec4_t)

struct vec4_t {
    union {
        struct {
            num_t x;
            num_t y;
            num_t z;
            num_t w;
        };
        num_t arr[4];
    };
};

// creation
vec4_t pre(vec4)(num_t x = num_t(0));
vec4_t pre(vec4)(num_t x, num_t y, num_t z, num_t w);

void vec4_set(vec4_t& out, num_t x, num_t y, num_t z, num_t w);

void vec4_zero(vec4_t& out);
vec4_t pre(vec4n_zero)();

void vec4_copy(vec4_t& out, const vec4_t& v);
vec4_t vec4n_copy(const vec4_t& v);
