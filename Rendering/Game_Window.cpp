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

void Game_Window::Draw_Rectangle(int x1, int y1, int x2, int y2, Uint32 colour) {
    // do stuff
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)surf->pixels + (y1 * surf->pitch) + (x1 * bytes));

    if (x2 >= winWidth) {x2 = winWidth - 1;}
    if (y2 >= winHeight) {y2 = winHeight - 1;}

    if (x1 < 0 || x1 >= winWidth) return;
    if (y1 < 0 || y1 >= winHeight) return;


    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * surf->pitch) + (x * bytes));
            *pixel = colour;
        }
    }

    SDL_BlitSurface(surf, NULL, winSurf, NULL);
    SDL_UpdateWindowSurface(window);
}

void Game_Window::Clear_Surf(Uint32 colour) {
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)surf->pixels);

    for (int y = 0; y < winHeight; y++) {
        for (int x = 0; x < winWidth; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * surf->pitch) + (x * bytes));
            *pixel = colour;
        }
    }
}