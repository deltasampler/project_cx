#include <stdio.h>
#include <cl/math/math_r.h>
#include <cl/math/math_i.h>

// float
#include "../vec3/struct_f.h"
#include "../vec4/struct_f.h"
#include "struct_f.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// double
#include "../vec3/struct_d.h"
#include "../vec4/struct_d.h"
#include "struct_d.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "real.cpp"
#include "transf.cpp"

// int
#include "../vec3/struct_s.h"
#include "../vec4/struct_s.h"
#include "struct_s.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat4_str(const mat4_t& m, char* str) {
    sprintf(
        str,
        "mat4(\n\t%i, %i, %i, %i,\n\t%i, %i, %i, %i,\n\t%i, %i, %i, %i\n\t%i, %i, %i, %i\n)",
        m.e00, m.e10, m.e20, m.e30,
        m.e01, m.e11, m.e21, m.e31,
        m.e02, m.e12, m.e22, m.e32,
        m.e03, m.e13, m.e23, m.e33
    );
}

// uint
#include "../vec3/struct_u.h"
#include "../vec4/struct_u.h"
#include "struct_u.h"
#include "struct.cpp"
#include "base.h"
#include "base.cpp"
#include "int.cpp"

// string
void mat4_str(const mat4_t& m, char* str) {
    sprintf(
        str,
        "mat4(\n\t%u, %u, %u, %u,\n\t%u, %u, %u, %u,\n\t%u, %u, %u, %u\n\t%u, %u, %u, %u\n)",
        m.e00, m.e10, m.e20, m.e30,
        m.e01, m.e11, m.e21, m.e31,
        m.e02, m.e12, m.e22, m.e32,
        m.e03, m.e13, m.e23, m.e33
    );
}
