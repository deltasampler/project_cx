set(
    PROJECT_SOURCE
    "source/main.cpp"
)

add_executable(project ${PROJECT_SOURCE} ${IMGUI_SDL_SOURCE} ${IMGUI_GL_SOURCE})
target_include_directories(project PUBLIC ${SDL3_INCLUDE_DIR})
target_link_libraries(project cl)
target_link_libraries(project ${SDL3_LIBRARIES})
target_link_libraries(project gl)
target_link_libraries(project imgui)
target_link_libraries(project examples)

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET project PROPERTY CXX_STANDARD 20)
endif()

# set_source_files_properties(source/main.cpp
#     PROPERTIES COMPILE_FLAGS "-E"
# )
