add_compile_definitions(MODULE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")

set(
    IMGUI_SOURCE
    "source/imgui/imgui_demo.cpp"
    "source/imgui/imgui_draw.cpp"
    "source/imgui/imgui_tables.cpp"
    "source/imgui/imgui_widgets.cpp"
    "source/imgui/imgui.cpp"
)

set(
    IMGUI_SDL_SOURCE
    "${CMAKE_CURRENT_LIST_DIR}/source/imgui_sdl/imgui_impl_sdl3.cpp"
    CACHE INTERNAL "IMGUI_SDL_SOURCE"
)

set(
    IMGUI_GL_SOURCE
    "${CMAKE_CURRENT_LIST_DIR}/source/imgui_gl/imgui_impl_opengl3.cpp"
    CACHE INTERNAL "IMGUI_GL_SOURCE"
)

add_library(imgui ${IMGUI_SOURCE})
target_include_directories(imgui PUBLIC "source/")
