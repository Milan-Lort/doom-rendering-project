#include <string>
#include "Game_Window.h"

#include "../Types/Types.h"

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

void Game_Window::Set_Px(int x, int y, Uint32 colour) {
    Uint32* pixel = (Uint32*)((Uint8*)surf->pixels + (y * surf->pitch) + (x * 4)); // is the number of bytes in a 32 bit unsigned integer
    *pixel = colour;
}

void Game_Window::Draw_Line(Vec2 p1, Vec2 p2, Uint32 colour) {
    int dx, dy;

    if (p1.x < p2.x) {dx = p2.x - p1.x;}
    else {dx = p1.x - p2.x;}

    if (p1.y < p2.y) {dy = p2.y - p1.y;}
    else {dy = p1.y - p2.y;}

    int dirX = p1.x < p2.x ? 1 : -1;
    int dirY = p1.y < p2.y ? 1 : -1;

    int err = (dy < dx ? dx : -dy)/2;
    int e2;

    while (true) {
        this->Set_Px(p1.x, p1.y, colour);
        if (p1.x == p2.x && p1.y == p2.y) break;

        // calculate the new iteration of pixel positions
        // look more into how this works exactly
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            p1.x += dirX;
        }
        if (e2 < dy) {
            err += dx;
            p1.y += dirY;
        }
    }

    SDL_BlitSurface(surf, NULL, winSurf, NULL);
    SDL_UpdateWindowSurface(window);
}