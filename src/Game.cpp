#include <SDL3/SDL.h>

#include "./headers/Game.h"

using namespace rendering;

Game::Game() {
    float deltaTime = 0;
    frameCount = 0;
}

void Game::Play_Game() {
    Uint64 now, last;
    now = SDL_GetPerformanceCounter();
    last = 0;
    while (true) {
        frameCount++;
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (now - last) / (float)SDL_GetPerformanceFrequency();

        this->Update_Logic();
        if (frameCount % 5 == 0) {this->Update_Render();}
    }
}

void Game::Update_Logic() {
    camera.Handle_Movement(deltaTime);
}

void Game::Update_Render() {
    // go through all walls in the level and draw them to the screen
    // do culling within the camera class
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

    camera.Clear_Screen();
    camera.Wireframe_Render_Wall(testSquare, testColour2);

    mainWindow.Update_Window();
}