#include <SDL3/SDL_events.h>
#include <iostream>

#include "Player.h"

using namespace player;

Player::Player() {
    xPos = 0;
    yPos = 0;
    rotation = 0;

    velocity = 0;
}

void Player::Handle_Input() {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();

    if (key_states[SDL_SCANCODE_W]) {yPos -= 1;}
    if (key_states[SDL_SCANCODE_S]) {yPos += 1;}

    if (key_states[SDL_SCANCODE_D]) {xPos += 1;}
    if (key_states[SDL_SCANCODE_A]) {xPos -= 1;}
}

int Player::Get_xPos() {
    return xPos;
}

int Player::Get_yPos() {
    return yPos;
}