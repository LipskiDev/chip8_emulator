#include <stdio.h>
#include "screen.h"

int main() {
    SDL_Window *sdl_screen;
    SDL_Renderer *sdl_renderer;
    SDL_Texture *sdl_texture;

    SDL_Init(SDL_INIT_EVERYTHING);
    initialize_window(sdl_screen, sdl_renderer, sdl_texture);

    while(1) {

    }

    close_window(sdl_screen, sdl_renderer, sdl_texture);

    return 0;
}