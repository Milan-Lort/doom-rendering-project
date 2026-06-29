#include <SDL3/SDL.h>
#include <iostream>

#include "./headers/Game.h"

using namespace rendering;

Game::Game() {
    float deltaTime = 0;
    levelGeometry = currLevel.getLevelGeometry();
}

void Game::Play_Game() {
    // Uint64s used to track game timing
    Uint64 now, last;
    Uint64 lastUpdate = SDL_GetPerformanceCounter();
    now = SDL_GetPerformanceCounter();
    last = 0;

    // event is used to tell when to quit the game
    SDL_Event event;

    /*
        Game Loop checks to see if game should quick due to window closure
        Then timing is updated and rendering and logic updates can be called
        Logic does not update every frame, but rather as a fixed duration
        In final version logic updates for physics etc should probably be differentiated from movement
        Movement should then be left to update every frame
        For now keep as is
    */
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        frameCount++;
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (now - last) / (float)SDL_GetPerformanceFrequency();

        if ((now - lastUpdate) / (float)SDL_GetPerformanceFrequency() >= LOGIC_UPDATE_TIME) {
            lastUpdate = now;
            this->Update_Logic();
        }

        this->Update_Render();
    }
}

void Game::Update_Logic() {
    camera.Handle_Movement(deltaTime);
}

void Game::Update_Render() {
    camera.Clear_Screen();
    // go through all walls in the level and draw them to the screen
    // do culling within the camera class
    Uint32 testColour2 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 255, 100);
    Uint32 testColour3 = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 255, 0, 0, 100);


    for (int i = 0; i < levelGeometry.size(); i++) {
        camera.Wireframe_Render_Wall(levelGeometry[i], testColour2);
    }

    mainWindow.Update_Window();
}