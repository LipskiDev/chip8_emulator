#include <stdio.h>
#include <SDL2/SDL.h>
#include "screen.h"

int main() {
    SDL_Window *sdl_screen;
    SDL_Renderer *sdl_renderer;
    SDL_Texture *sdl_texture;

    int quit = 0;
    SDL_Event event;

    initialize_window(&sdl_screen, &sdl_renderer, &sdl_texture);

    while(!quit) {
        // input
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            quit = 1;
                            break;
                    }
            }
        }
        // update

        // render

    }

    close_window(&sdl_screen, &sdl_renderer, &sdl_texture);

    return 0;
}