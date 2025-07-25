// comparison
bool mat4_equals(const mat4_t& m0, const mat4_t& m1) {
    return m0.e00 == m1.e00 && m0.e01 == m1.e01 && m0.e02 == m1.e02 && m0.e03 == m1.e03 &&
           m0.e10 == m1.e10 && m0.e11 == m1.e11 && m0.e12 == m1.e12 && m0.e13 == m1.e13 &&
           m0.e20 == m1.e20 && m0.e21 == m1.e21 && m0.e22 == m1.e22 && m0.e23 == m1.e23 &&
           m0.e30 == m1.e30 && m0.e31 == m1.e31 && m0.e32 == m1.e32 && m0.e33 == m1.e33;
}
