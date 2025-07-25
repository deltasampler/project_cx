// comparison
bool mat2_equals(const mat2_t& m0, const mat2_t& m1) {
    return m0.e00 == m1.e00 && m0.e01 == m1.e01 &&
           m0.e10 == m1.e10 && m0.e11 == m1.e11;
}
