#include <string>
#include "Game_Window.h"

using namespace std;
using namespace rendering;

Game_Window::Game_Window(const char* title, int width, int height) {
    // define the function
    winWidth = width;
    winHeight= height;
    window = SDL_CreateWindow(title, width, height, 0);
    // add errror handling later
    surf = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_ARGB32);
    winSurf = SDL_GetWindowSurface(window);
}

void Game_Window::Draw_Blank_Screen() {
    SDL_BlitSurface(surf, NULL, winSurf, NULL);

    SDL_UpdateWindowSurface(window);
}

void Game_Window::Draw_Point(int x, int y, Uint32 colour) {
    // we can cast to uint32 to define it as an array of uints
    Uint8* pixel = (Uint8*)surf->pixels;
    int bytes = sizeof(Uint32);

    // we have the pitch is the distance between the rows of pixels in bytes
    pixel = pixel + (y * surf->pitch) + (x * bytes);
    *(Uint32*) pixel = colour;

    SDL_BlitSurface(surf, NULL, winSurf, NULL);

    SDL_UpdateWindowSurface(window);
}

void Game_Window::Draw_Rectangle(int x1, int y1, int x2, int y2, Uint32 colour) {
    // do stuff
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)surf->pixels + (y1 * surf->pitch) + (x1 * bytes));

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * surf->pitch) + (x * bytes));
            *pixel = colour;
        }
    }

    SDL_BlitSurface(surf, NULL, winSurf, NULL);
    SDL_UpdateWindowSurface(window);
}