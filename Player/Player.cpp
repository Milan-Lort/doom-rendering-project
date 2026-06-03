#include <SDL3/SDL_events.h>
#include <iostream>

#include "Player.h"

using namespace player;

Player::Player() {
    position[0] = 0;
    position[1] = 0;

    faceDir[0] = 1;
    faceDir[1] = 0;

    movDir[0] = 0;
    movDir[1] = 0;

    velocity = 0;
}

void Player::Handle_Input() {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();

    if (key_states[SDL_SCANCODE_W]) {position[0] += 1;}
    if (key_states[SDL_SCANCODE_S]) {position[0] -= 1;}

    std::cout<<position[0]<<std::endl;
}