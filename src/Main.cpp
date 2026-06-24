#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <iostream>

#include "./headers/Game_Window.h"
#include "./headers/Player.h"
#include "./headers/Types.h"
#include "./headers/Game.h"

using namespace rendering;
using namespace player;

int main() {
    // initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed!");
        return -1;
    } // for now only video is initialized, need to initialize more as we add functionality

    Game game = Game();

    game.Play_Game();

    SDL_Quit(); // 
    return 0;
}