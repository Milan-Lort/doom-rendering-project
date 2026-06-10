#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include "Rendering/Game_Window.h"
#include "Player/Player.h"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 300

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
    
    Uint32 testColour = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 0, 100);
    Uint32 testColour2 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 255, 100);
    
    mainWindow.Draw_Rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, testColour);
    
    while(true) {
        player.Handle_Input();
        
        mainWindow.Clear_Surf(testColour);
        Vec2 p1;
        p1.x = 0;
        p1.y = 0;
        Vec2 p2;
        p2.x = (int)player.Get_xPos();
        p2.y = (int)player.Get_yPos();
        mainWindow.Draw_Line(p1, p2, testColour2);
    }


    SDL_Delay(5000);

    SDL_Quit(); // 
    return 0;
}