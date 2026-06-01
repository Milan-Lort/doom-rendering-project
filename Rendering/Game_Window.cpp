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
}

void Game_Window::Draw_Blank_Screen() {
    SDL_Texture* blank = NULL;
    SDL_Surface* surface = NULL;

    surface = SDL_CreateSurface(winWidth, winHeight, SDL_PIXELFORMAT_RGB24);
    blank = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, blank, NULL, NULL);
    SDL_RenderPresent(renderer);
}