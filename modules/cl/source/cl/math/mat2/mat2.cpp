#include <stdio.h>
#include <cl/math/math_r.h>
#include <cl/math/math_i.h>

// float
#include "../vec2/struct_f.h"
#include "struct_f.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// double
#include "../vec2/struct_d.h"
#include "struct_d.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// int
#include "../vec2/struct_s.h"
#include "struct_s.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat2_str(const mat2_t& m, char* str) {
    sprintf(
        str,
        "mat2(\n\t%i, %i,\n\t%i, %i\n)",
        m.e00, m.e10,
        m.e01, m.e11
    );
}

// uint
#include "../vec2/struct_u.h"
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat2_str(const mat2_t& m, char* str) {
    sprintf(
        str,
        "mat2(\n\t%u, %u,\n\t%u, %u\n)",
        m.e00, m.e10,
        m.e01, m.e11
    );
}
