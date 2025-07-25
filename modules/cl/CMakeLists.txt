add_compile_definitions(MODULE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")

set(
    CL_SOURCE
    "source/cl/camera/cam2.cpp"
    "source/cl/camera/cam3.cpp"
    "source/cl/compiler/lexer.cpp"
    "source/cl/compiler/scanner.cpp"
    "source/cl/compiler/token.cpp"
    "source/cl/math/mat2/mat2.cpp"
    "source/cl/math/mat3/mat3.cpp"
    "source/cl/math/mat4/mat4.cpp"
    "source/cl/math/vec2/vec2.cpp"
    "source/cl/math/vec3/vec3.cpp"
    "source/cl/math/vec4/vec4.cpp"
    "source/cl/math/math_i.cpp"
    "source/cl/math/math_r.cpp"
    "source/cl/math/rand_r.cpp"
    "source/cl/string/cstr.cpp"
    "source/cl/string/dstr.cpp"
    "source/cl/string/sstr.cpp"
)

add_library(cl ${CL_SOURCE})
target_include_directories(cl PUBLIC "source/")
