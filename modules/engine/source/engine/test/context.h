#pragma once

#include <SDL3/SDL.h>
#include <cl/types.h>

struct context_t {
    SDL_Window* window;
    s32 viewport_x;
    s32 viewport_y;
};

context_t context;

void init();
void shut();
void process_event(SDL_Event& event);
void update();
void render();
void gui();
