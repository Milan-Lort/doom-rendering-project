#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

using namespace std;

//namespace rendering {

class Game_Window {
    private:

    public:
    SDL_Window* window;
    SDL_Renderer* renderer;

    Game_Window(const char* title, int width, int height);
};

//}

#endif