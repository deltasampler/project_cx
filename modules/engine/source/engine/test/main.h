#pragma once

#include <stdio.h>
#include <SDL3/SDL.h>
#include <glad/gl.h>

#ifdef USE_IMGUI
    #include <imgui/imgui.h>
    #include <imgui_sdl/imgui_impl_sdl3.h>
    #include <imgui_gl/imgui_impl_opengl3.h>
#endif

#include "context.h"

s32 main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        printf("ERROR: SDL_Init(): %s\n", SDL_GetError());

        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    u32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    context.window = SDL_CreateWindow("Project", 1280, 720, window_flags);

    if (context.window == nullptr) {
        printf("ERROR: SDL_CreateWindow(): %s\n", SDL_GetError());

        return -1;
    }

    SDL_SetWindowPosition(context.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_GLContext gl_context = SDL_GL_CreateContext(context.window);

    if (gl_context == nullptr) {
        printf("ERROR: SDL_GL_CreateContext(): %s\n", SDL_GetError());

        return -1;
    }

    SDL_GL_MakeCurrent(context.window, gl_context);
    SDL_GL_SetSwapInterval(1);
    SDL_ShowWindow(context.window);

    if (gladLoadGL(GLADloadfunc(SDL_GL_GetProcAddress)) == 0) {
        printf("ERROR: gladLoadGL()\n");

        return -1;
    }

    #ifdef USE_IMGUI
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();
        ImGuiStyle& style = ImGui::GetStyle();

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplSDL3_InitForOpenGL(context.window, gl_context);
        ImGui_ImplOpenGL3_Init("#version 130");
    #endif

    bool running = true;
    SDL_GetWindowSize(context.window, &context.viewport_x, &context.viewport_y);

    init();

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }

            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(context.window)) {
                running = false;
            }

            if (event.type == SDL_EVENT_WINDOW_RESIZED && event.window.windowID == SDL_GetWindowID(context.window)) {
                SDL_GetWindowSize(context.window, &context.viewport_x, &context.viewport_y);
            }

            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.scancode == SDL_SCANCODE_GRAVE) {
                    SDL_SetWindowRelativeMouseMode(context.window, !SDL_GetWindowRelativeMouseMode(context.window));
                }
            }

            #ifdef USE_IMGUI
                if (!SDL_GetWindowRelativeMouseMode(context.window)) {
                    ImGui_ImplSDL3_ProcessEvent(&event);
                }
            #endif

            process_event(event);
        }

        if (SDL_GetWindowFlags(context.window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(10);

            continue;
        }

        update();

        #ifdef USE_IMGUI
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL3_NewFrame();
            ImGui::NewFrame();

            gui();

            ImGui::Render();
        #endif

        glViewport(0, 0, context.viewport_x, context.viewport_y);
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render();

        #ifdef USE_IMGUI
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
                SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
            }
        #endif

        SDL_GL_SwapWindow(context.window);
    }

    #ifdef USE_IMGUI
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
    #endif

    shut();

    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(context.window);
    SDL_Quit();

    return 0;
}
