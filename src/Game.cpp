#include <SDL3/SDL.h>

#include "./headers/Game.h"

using namespace rendering;

Game::Game() {
    float deltaTime = 0;
}

void Game::Play_Game() {
    Uint64 now, last;
    now = SDL_GetPerformanceCounter();
    last = 0;
    while (true) {
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (now - last) / (float)SDL_GetPerformanceFrequency();

        this->Update_Logic();
        this->Update_Render();
    }
}

void Game::Update_Logic() {
    camera.Handle_Movement(deltaTime);
}

void Game::Update_Render() {
    // do stuff
}