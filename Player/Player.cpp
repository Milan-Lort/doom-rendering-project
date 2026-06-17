#include <SDL3/SDL_events.h>
#include <math.h>
#include <iostream>

#include "Player.h"

using namespace player;

Player::Player() {
    pos.x = 400;
    pos.y = 300;

    rotation = 0;
    rotSpeed = 0.01;

    velocity = 0.6;
}

bool Player::Handle_Input() {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();
    // TODO: Change the movement direction to be relative to the rotation of the player
    if (key_states[SDL_SCANCODE_W]) {
        pos.y -= velocity * cos(rotation);
        pos.x -= velocity * sin(rotation);
    }
    if (key_states[SDL_SCANCODE_S]) {
        pos.y += velocity * cos(rotation);
        pos.x += velocity * sin(rotation);
    }

    if (key_states[SDL_SCANCODE_UP]) {
        pos.y -= velocity * cos(rotation);
        pos.x -= velocity * sin(rotation);
    }
    if (key_states[SDL_SCANCODE_DOWN]) {
        pos.y += velocity * cos(rotation);
        pos.x += velocity * sin(rotation);
    }

    if (key_states[SDL_SCANCODE_D]) {
        pos.x -= velocity * cos(rotation);
        pos.y -= velocity * sin(rotation);
    }
    if (key_states[SDL_SCANCODE_A]) {
        pos.x += velocity * cos(rotation);
        pos.y += velocity * sin(rotation);
    }

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