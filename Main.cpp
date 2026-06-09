#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include "Rendering/Game_Window.h"
#include "Player/Player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace rendering;
using namespace player;

int main() {
    // initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed!");
        return -1;
    } // for now only video is initialized, need to initialize more as we add functionality

    // create a window
    Game_Window mainWindow("Main Window", SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // create a player
    Player player;
    
    Uint32 testColour = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 255, 0, 0, 100);
    Uint32 testColour2 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 255, 100);
    
    mainWindow.Draw_Rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, testColour);
    
    while(true) {
        player.Handle_Input();
        
        mainWindow.Clear_Surf(testColour);
        mainWindow.Draw_Rectangle(player.Get_xPos(), player.Get_yPos() , 50 + player.Get_xPos(), 50 + player.Get_yPos(), testColour2);
    }


    SDL_Delay(5000);

    SDL_Quit(); // 
    return 0;
}