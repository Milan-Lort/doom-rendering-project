#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <string>

#include "Game_Window.h"
#include "Camera.h"
#include "Player.h"
#include "Types.h"
#include "Level.h"

using namespace rendering;
using namespace player;
using namespace level;

namespace rendering {
    
class Game {
    private:

    // Player and level stuff
    Player player = Player();
    Level currLevel = Level("./levels/examplelvl.txt");
    vector<Wall> levelGeometry;
    
    // Rendering stuff
    Uint64 frameCount;
    SDL_Surface* drawSurf = SDL_CreateSurface(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_PIXELFORMAT_ARGB32);
    Game_Window mainWindow = Game_Window("Main Window", SCREEN_WIDTH, SCREEN_HEIGHT, drawSurf);
    Camera camera = Camera(drawSurf);

    float deltaTime;
    
    /*
        Update_Logic() should run every iteration of the game loop and handle things like AI and game movement
        Update_Render() should be called at a consistent interval and be used to render frames to the screen
    */
    void Update_Logic();

    void Update_Render();

    public:

    Game();

    void Select_Level();

    void Play_Game(); // use this to run the game loop
};

}


#endif