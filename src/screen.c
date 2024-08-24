#include "screen.h"

void initialize_window(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture) {
    window = SDL_CreateWindow(
        "Chip-8 Emulator",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    if(window == NULL) {
        fprintf(stderr, "Could not create SDL Window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        0
    );

    if(renderer == NULL) {
        fprintf(stderr, "Could not create SDL Renderer: %s\n", SDL_GetError());
        exit(1);
    }

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );

    if(texture == NULL) {
        fprintf(stderr, "Could not create SDL Texture: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

void close_window(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}
