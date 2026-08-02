#include <SDL3/SDL_events.h>
#include <math.h>
#include <iostream>

#include "./headers/Camera.h"

using namespace rendering;
using namespace std;

Camera::Camera(SDL_Surface* surf) {
    drawSurf = surf;

    pos.x = 400;
    pos.y = 300;

    rotation = 0;
    rotSpeed = 2.5;

    velocity = 20;

    black = SDL_MapRGBA(SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_ARGB32), NULL, 0, 0, 0, 100);

    strafeRotOff = M_PI / 4;
}

void Camera::Handle_Movement(float deltaTime) {
    // get player input and make necesssary changed depending on what it is

    SDL_PumpEvents();
    // TODO: Change the movement direction to be relative to the rotation of the player
    if (key_states[SDL_SCANCODE_W] || key_states[SDL_SCANCODE_UP]) {
        pos.y += velocity * cos(rotation) * deltaTime;
        pos.x += velocity * sin(rotation) * deltaTime;
    }
    if (key_states[SDL_SCANCODE_S] || key_states[SDL_SCANCODE_DOWN]) {
        pos.y -= velocity * cos(rotation) * deltaTime;
        pos.x -= velocity * sin(rotation) * deltaTime;
    }

    // TODO: Fix strafing
    if (key_states[SDL_SCANCODE_D]) {
        pos.x -= velocity * cos(rotation) * deltaTime;
        pos.y -= velocity * sin(rotation) * deltaTime;
    }
    if (key_states[SDL_SCANCODE_A]) {
        pos.x += velocity * cos(rotation) * deltaTime;
        pos.y += velocity * sin(rotation) * deltaTime;
    }

    if (key_states[SDL_SCANCODE_RIGHT]) {rotation -= rotSpeed * deltaTime;}
    if (key_states[SDL_SCANCODE_LEFT]) {rotation += rotSpeed * deltaTime;}
}

void Camera::Clear_Screen() {
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)drawSurf->pixels);

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * drawSurf->pitch) + (x * bytes));
            *pixel = black;
        }
    }
}

void Camera::Set_Px(Vec2 p, Uint32 colour) {
    if (p.x < 0 || p.x >= SCREEN_WIDTH) return;
    else if (p.y < 0 || p.y >= SCREEN_HEIGHT) return;
    Uint32* pixel = (Uint32*)((Uint8*)drawSurf->pixels + (p.y * drawSurf->pitch) + (p.x * 4)); // is the number of bytes in a 32 bit unsigned integer
    *pixel = colour;
}

void Camera::Render_Line(Vec2 p1, Vec2 p2, Uint32 colour) {
    int dx, dy;
    
    //cout<<"("<<p1.x<<","<<p1.y<<") ("<<p2.x<<","<<p2.y<<")"<<endl;
    if (p1.x < p2.x) {dx = p2.x - p1.x;}
    else {dx = p1.x - p2.x;}

    if (p1.y < p2.y) {dy = p2.y - p1.y;}
    else {dy = p1.y - p2.y;}

    int dirX = p1.x < p2.x ? 1 : -1;
    int dirY = p1.y < p2.y ? 1 : -1;
    
    int err = (dy < dx ? dx : -dy)/2;
    int e2;

    while (true) {
        this->Set_Px(p1, colour);
        if (p1.x == p2.x && p1.y == p2.y) break;

        // calculate the new iteration of pixel positions
        // look more into how this works exactly
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            p1.x += dirX;
        }
        if (e2 < dy) {
            err += dx;
            p1.y += dirY;
        }
    }
}

void Camera::Wireframe_Render_Wall(Wall wall, Uint32 colour) {
    float x1, x2, y1, y2;
    float distX1, distX2, distY1, distY2;
    x1 = wall.a.x - pos.x;
    x2 = wall.b.x - pos.x;
    y1 = wall.a.y - pos.y;
    y2 = wall.b.y - pos.y;

    distX1 = x1 * cos(rotation) - y1 * sin(rotation);
    distY1 = x1 * sin(rotation) + y1 * cos(rotation);
    distX2 = x2 * cos(rotation) - y2 * sin(rotation);
    distY2 = x2 * sin(rotation) + y2 * cos(rotation);

    if (distY1 < 0 && distY2 < 0) return;
    else if (distY1 < 0) {
        // set the point to be inline with the player
        float dy = distY2 - distY1;
        float dx = distX2 - distX1;
        float mInv = dx / dy;

        distX1 -= mInv * distY1;
        distY1 = 0.1;
    } else if (distY2 < 0) {
        // set the point to be inline with the player
        float dy = distY2 - distY1;
        float dx = distX2 - distX1;
        float mInv = dx / dy;

        distX2 -= mInv * distY2;
        distY2 = 0.1;
    }

    float scrnCentH = SCREEN_WIDTH / 2;
    float scrnCentW = SCREEN_WIDTH / 2;
    float fov = (SCREEN_WIDTH * SCREEN_WIDTH) / 60;

    float playerHeight = 100;

    x1 = -distX1 * scrnCentW / distY1;
    x2 = -distX2 * scrnCentW / distY2;
    float y1a = -(wall.h + fov) / distY1;
    float y2a = -(wall.h + fov) / distY2;
    float y1b = (fov) / distY1;
    float y2b = (fov) / distY2;

    Vec2 p1, p2, p3, p4;
    p1.x = scrnCentW + x1;
    p1.y = scrnCentH + y1a;
    p2.x = scrnCentW + x2;
    p2.y = scrnCentH + y2a;
    p3.x = scrnCentW + x2;
    p3.y = scrnCentW + y2b;
    p4.x = scrnCentW + x1;
    p4.y = scrnCentH + y1b;

    this->Render_Line(p1, p2, colour);
    this->Render_Line(p2, p3, colour);
    this->Render_Line(p3, p4, colour);
    this->Render_Line(p4, p1, colour);
}
