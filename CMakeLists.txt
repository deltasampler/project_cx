cmake_minimum_required(VERSION 3.8)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("cmake_build")

add_compile_definitions(ROOT_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")
add_compile_definitions(CL_PATH="${CMAKE_CURRENT_SOURCE_DIR}/cl/")
add_compile_definitions(ENGINE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/engine/")
add_compile_definitions(EXAMPLES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/examples/")
add_compile_definitions(GL_PATH="${CMAKE_CURRENT_SOURCE_DIR}/gl/")
add_compile_definitions(IMGUI_PATH="${CMAKE_CURRENT_SOURCE_DIR}/imgui/")
add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}/project/")

add_subdirectory("modules/cl")
find_package(SDL3 REQUIRED CONFIG)
add_subdirectory("modules/gl")
add_subdirectory("modules/imgui")
add_subdirectory("modules/engine")
add_subdirectory("modules/examples")
add_subdirectory("project")
