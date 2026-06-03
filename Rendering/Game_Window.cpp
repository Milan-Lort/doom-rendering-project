#include <string>
#include "Game_Window.h"

using namespace std;
using namespace rendering;

Game_Window::Game_Window(const char* title, int width, int height) {
    // define the function
    winWidth = width;
    winHeight= height;
    window = SDL_CreateWindow(title, width, height, 0);
    // add error handling later
    renderer = SDL_CreateRenderer(window, NULL);
    // add errror handling later
    surf = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_ARGB32);

    texture = SDL_CreateTextureFromSurface(renderer, surf);
}

void Game_Window::Draw_Blank_Screen() {

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Game_Window::Draw_Point(int x, int y, Uint32 colour) {
    // we can cast to uint32 to define it as an array of uints
    Uint8* pixel = (Uint8*)surf->pixels;
    int bytes = sizeof(Uint32);

    // we have the pitch is the distance between the rows of pixels in bytes
    pixel = pixel + (y * surf->pitch) + (x * bytes);
    *(Uint32*) pixel = colour;

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}