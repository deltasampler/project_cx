#include <stdio.h>
#include <cl/math/math_r.h>
#include <cl/math/math_i.h>

// float
#include "../vec2/struct_f.h"
#include "../vec3/struct_f.h"
#include "struct_f.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// double
#include "../vec2/struct_d.h"
#include "../vec3/struct_d.h"
#include "struct_d.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// int
#include "../vec2/struct_s.h"
#include "../vec3/struct_s.h"
#include "struct_s.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat3_str(const mat3_t& m, char* str) {
    sprintf(
        str,
        "mat3(\n\t%i, %i, %i,\n\t%i, %i, %i,\n\t%i, %i, %i\n)\n",
        m.e00, m.e10, m.e20,
        m.e01, m.e11, m.e21,
        m.e02, m.e12, m.e22
    );
}

// uint
#include "../vec2/struct_u.h"
#include "../vec3/struct_u.h"
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat3_str(const mat3_t& m, char* str) {
    sprintf(
        str,
        "mat3(\n\t%u, %u, %u,\n\t%u, %u, %u,\n\t%u, %u, %u\n)\n",
        m.e00, m.e10, m.e20,
        m.e01, m.e11, m.e21,
        m.e02, m.e12, m.e22
    );
}
