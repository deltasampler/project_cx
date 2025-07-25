// comparison
bool mat3_equals(const mat3_t& m0, const mat3_t& m1) {
    return m0.e00 == m1.e00 && m0.e01 == m1.e01 && m0.e02 == m1.e02 &&
           m0.e10 == m1.e10 && m0.e11 == m1.e11 && m0.e12 == m1.e12 &&
           m0.e20 == m1.e20 && m0.e21 == m1.e21 && m0.e22 == m1.e22;
}
