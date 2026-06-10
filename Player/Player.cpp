#include <SDL3/SDL_events.h>
#include <iostream>

#include "Player.h"

using namespace player;

Player::Player() {
    pos.x = 0;
    pos.y = 0;
    rotation = 0;

    velocity = 0;
}

void Player::Handle_Input() {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();

    if (key_states[SDL_SCANCODE_W]) {pos.y -= 1.0;}
    if (key_states[SDL_SCANCODE_S]) {pos.y += 1.0;}

    if (key_states[SDL_SCANCODE_D]) {pos.x += 1.0;}
    if (key_states[SDL_SCANCODE_A]) {pos.x -= 1.0;}
}

float Player::Get_xPos() {
    return pos.x;
}

float Player::Get_yPos() {
    return pos.y;
}