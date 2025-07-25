#undef mat4_t
#define mat4_t pre(mat4_t)

struct mat4_t {
    union {
        struct {
            num_t e00; num_t e01; num_t e02; num_t e03;
            num_t e10; num_t e11; num_t e12; num_t e13;
            num_t e20; num_t e21; num_t e22; num_t e23;
            num_t e30; num_t e31; num_t e32; num_t e33;
        };
        struct {
            num_t i0; num_t i1; num_t i2; num_t i3;
            num_t i4; num_t i5; num_t i6; num_t i7;
            num_t i8; num_t i9; num_t i10; num_t i11;
            num_t i12; num_t i13; num_t i14; num_t i15;
        };
        num_t arr[16];
    };
};

// creation
mat4_t pre(mat4)(num_t x = num_t(1));
mat4_t pre(mat4)(num_t e00, num_t e01, num_t e02, num_t e03, num_t e10, num_t e11, num_t e12, num_t e13, num_t e20, num_t e21, num_t e22, num_t e23, num_t e30, num_t e31, num_t e32, num_t e33);

void mat4_set(mat4_t& out, num_t e00, num_t e01, num_t e02, num_t e03, num_t e10, num_t e11, num_t e12, num_t e13, num_t e20, num_t e21, num_t e22, num_t e23, num_t e30, num_t e31, num_t e32, num_t e33);

void mat4_zero(mat4_t& out);
mat4_t pre(mat4n_zero)();

void mat4_ident(mat4_t& out);
mat4_t pre(mat4n_ident)();

void mat4_copy(mat4_t& out, const mat4_t& m);
mat4_t mat4n_copy(const mat4_t& m);
