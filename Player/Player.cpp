#include <SDL3/SDL_events.h>
#include <iostream>

#include "Player.h"

using namespace player;

Player::Player() {
    pos.x = 0;
    pos.y = 0;

    rotation = 0;
    rotSpeed = 0.002;

    velocity = 0.1;
}

bool Player::Handle_Input() {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();

    if (key_states[SDL_SCANCODE_W]) {pos.y -= velocity;}
    if (key_states[SDL_SCANCODE_S]) {pos.y += velocity;}

    if (key_states[SDL_SCANCODE_D]) {pos.x += velocity;}
    if (key_states[SDL_SCANCODE_A]) {pos.x -= velocity;}

    if (key_states[SDL_SCANCODE_RIGHT]) {rotation -= rotSpeed;}
    if (key_states[SDL_SCANCODE_LEFT]) {rotation += rotSpeed;}

    if (key_states[SDL_SCANCODE_ESCAPE]) {return false;}
    else {return true;}
}

float Player::Get_xPos() {
    return pos.x;
}

float Player::Get_yPos() {
    return pos.y;
}

float Player::Get_Rot() {
    return rotation;
}