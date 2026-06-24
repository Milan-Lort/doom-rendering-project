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
    
    Uint32 testColour = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 0, 100);
    Uint32 testColour2 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 255, 100);
    Uint32 testColour3 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 255, 0, 0, 100);
    Lineseg testLine;
    testLine.a.x = 250;
    testLine.a.y = 250;
    testLine.b.x = 275;
    testLine.b.y = 275;

    Wall testSquare;
    testSquare.a = testLine.a;
    testSquare.b = testLine.b;
    testSquare.h = 50;

    Game game = Game();

    game.Play_Game();

    SDL_Quit(); // 
    return 0;
}