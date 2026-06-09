#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

using namespace std;

namespace rendering {

class Game_Window {
    private:
    int winWidth;
    int winHeight;

    SDL_Renderer* renderer;
    SDL_Surface* surf;
    SDL_Surface* winSurf;

    public:
    SDL_Window* window;

    Game_Window(const char* title, int width, int height);

    void Draw_Rectangle(int x1, int y1, int x2, int y2, Uint32 colour);

    void Clear_Surf(Uint32 colour);
};

}

#endif