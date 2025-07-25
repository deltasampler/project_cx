add_compile_definitions(MODULE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")

set(
    STB_SOURCE
    "source/stb/stb.c"
)

set(
    ENGINE_SOURCE
    source/engine/renderers/sky_rend.cpp
    source/engine/renderers/point_rend.cpp
    source/engine/renderers/arrow2_rend.cpp
    source/engine/renderers/arrow3_rend.cpp
    source/engine/renderers/frame3_rend.cpp
    source/engine/renderers/line2_rend.cpp
    source/engine/renderers/line3_rend.cpp
    source/engine/renderers/ray_marcher.cpp
)

add_library(engine ${STB_SOURCE} ${ENGINE_SOURCE})
target_include_directories(engine PUBLIC "source/")
target_link_libraries(engine cl)
target_link_libraries(engine gl)
target_link_libraries(engine imgui)
