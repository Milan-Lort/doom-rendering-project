#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <iostream>

#include "Rendering/Game_Window.h"
#include "Player/Player.h"
#include "Types/Types.h"

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

    // set the game loop to run
    bool running = true;
    SDL_Event event;
    
    Uint32 testColour = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 0, 100);
    Uint32 testColour2 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 255, 100);
    Uint32 testColour3 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 255, 0, 0, 100);
    
    mainWindow.Draw_Rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, testColour); // set the window to a basic colour

    Lineseg testLine;
    testLine.a.x = 250;
    testLine.a.y = 450;
    testLine.b.x = 650;
    testLine.b.y = 150;

    Square testSquare;
    testSquare.a = testLine.a;
    testSquare.b = testLine.b;
    testSquare.h = 150;
    
    while(running) {
        // TODO: Implement time delta
        running = player.Handle_Input();
        
        mainWindow.Clear_Surf(testColour);
        // mainWindow.Render_Line(testLine, player, testColour2);
        mainWindow.DDA_Render_Square(testSquare, player, testColour2);
        mainWindow.Render_Player(player, testColour3);
    }


    // SDL_Delay(5000);
    SDL_DestroyWindow(mainWindow.window); // TODO: Make a suitable destructor for the Game_Window class so I don't have to do this all the time
    SDL_Quit(); // 
    return 0;
}