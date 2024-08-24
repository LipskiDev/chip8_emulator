#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

#define WINDOW_HEIGHT 960
#define WINDOW_WIDTH 1280

void initialize_window(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, SDL_Texture *sdl_texture);
void close_window(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, SDL_Texture *sdl_texture);


#endif // SCREEN_H
