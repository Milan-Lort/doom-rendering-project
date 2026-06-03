#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include "Rendering/Game_Window.h"
#include "Player/Player.h"

using namespace rendering;
using namespace player;

int main() {
    // initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed!");
        return -1;
    } // for now only video is initialized, need to initialize more as we add functionality

    // create a window
    Game_Window mainWindow("Main Window", 500, 500);

    // create a player
    Player player;

    Uint32 testColour = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 0, 100);

    mainWindow.Draw_Rectangle(0, 0, 500, 500, testColour);


    SDL_Delay(5000);

    SDL_Quit(); // 
    return 0;
}