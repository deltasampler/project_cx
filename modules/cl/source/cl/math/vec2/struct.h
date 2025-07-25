#undef vec2_t
#define vec2_t pre(vec2_t)

struct vec2_t {
    union {
        struct {
            num_t x;
            num_t y;
        };
        num_t arr[2];
    };
};

// creation
vec2_t pre(vec2)(num_t x = num_t(0));
vec2_t pre(vec2)(num_t x, num_t y);

void vec2_set(vec2_t& out, num_t x, num_t y);

void vec2_zero(vec2_t& out);
vec2_t pre(vec2n_zero)();

void vec2_copy(vec2_t& out, const vec2_t& v);
vec2_t vec2n_copy(const vec2_t& v);
