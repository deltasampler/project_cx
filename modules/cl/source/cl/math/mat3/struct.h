#undef mat3_t
#define mat3_t pre(mat3_t)

struct mat3_t {
    union {
        struct {
            num_t e00; num_t e01; num_t e02;
            num_t e10; num_t e11; num_t e12;
            num_t e20; num_t e21; num_t e22;
        };
        struct {
            num_t i0; num_t i1; num_t i2;
            num_t i3; num_t i4; num_t i5;
            num_t i6; num_t i7; num_t i8;
        };
        num_t arr[9];
    };
};

// creation
mat3_t pre(mat3)(num_t x = num_t(1));
mat3_t pre(mat3)(num_t e00, num_t e01, num_t e02, num_t e10, num_t e11, num_t e12, num_t e20, num_t e21, num_t e22);

void mat3_set(mat3_t& out, num_t e00, num_t e01, num_t e02, num_t e10, num_t e11, num_t e12, num_t e20, num_t e21, num_t e22);

void mat3_zero(mat3_t& out);
mat3_t pre(mat3n_zero)();

void mat3_ident(mat3_t& out);
mat3_t pre(mat3n_ident)();

void mat3_copy(mat3_t& out, const mat3_t& m);
mat3_t mat3n_copy(const mat3_t& m);
