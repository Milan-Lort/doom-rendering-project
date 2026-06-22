#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

#include "Game_Window.h"
#include "Player.h"
#include "Types.h"

using namespace rendering;
using namespace player;

class Game {
    private:
    Game_Window mainWindow;
    Player player;
    SDL_Surface* drawSurf;

    float deltaTime;
    
    /*
        Update_Logic() should run every iteration of the game loop and handle things like AI and game movement
        Update_Render() should be called at a consistent interval and be used to render frames to the screen
    */
    void Update_Logic();

    void Update_Render();

    public:

    Game();

    void Load_Level(const char* filename);

    void Play_Game(); // use this to run the game loop
};

#endif