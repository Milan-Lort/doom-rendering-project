#include <string>
#include <iostream>
#include <math.h>

#include "Game_Window.h"

#include "../Types/Types.h"
#include "../Player/Player.h"

using namespace std;
using namespace rendering;
using namespace player;

Game_Window::Game_Window(const char* title, int width, int height) {
    // define the function
    winWidth = width;
    winHeight= height;
    window = SDL_CreateWindow(title, width, height, 0);
    // add errror handling later
    surf = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_ARGB32);
    winSurf = SDL_GetWindowSurface(window);
}

void Game_Window::Draw_Rectangle(int x1, int y1, int x2, int y2, Uint32 colour) {
    // do stuff
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)surf->pixels + (y1 * surf->pitch) + (x1 * bytes));

    if (x2 >= winWidth) {x2 = winWidth - 1;}
    if (y2 >= winHeight) {y2 = winHeight - 1;}

    if (x1 < 0 || x1 >= winWidth) return;
    if (y1 < 0 || y1 >= winHeight) return;


    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * surf->pitch) + (x * bytes));
            *pixel = colour;
        }
    }

    SDL_BlitSurface(surf, NULL, winSurf, NULL);
    SDL_UpdateWindowSurface(window);
}

void Game_Window::Clear_Surf(Uint32 colour) {
    int bytes = sizeof(Uint32);
    Uint8* startPx = ((Uint8*)surf->pixels);

    for (int y = 0; y < winHeight; y++) {
        for (int x = 0; x < winWidth; x++) {
            Uint32* pixel = (Uint32*)(startPx + (y * surf->pitch) + (x * bytes));
            *pixel = colour;
        }
    }
}

void Game_Window::Set_Px(int x, int y, Uint32 colour) {
    if (x < 0 || x >= winWidth) return;
    else if (y < 0 || y >= winHeight) return;
    Uint32* pixel = (Uint32*)((Uint8*)surf->pixels + (y * surf->pitch) + (x * 4)); // is the number of bytes in a 32 bit unsigned integer
    *pixel = colour;
}

void Game_Window::Draw_Line(Vec2 p1, Vec2 p2, Uint32 colour) {
    int dx, dy;

    if (p1.x < p2.x) {dx = p2.x - p1.x;}
    else {dx = p1.x - p2.x;}

    if (p1.y < p2.y) {dy = p2.y - p1.y;}
    else {dy = p1.y - p2.y;}

    int dirX = p1.x < p2.x ? 1 : -1;
    int dirY = p1.y < p2.y ? 1 : -1;

    int err = (dy < dx ? dx : -dy)/2;
    int e2;

    while (true) {
        this->Set_Px(p1.x, p1.y, colour);
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

    SDL_BlitSurface(surf, NULL, winSurf, NULL);
    SDL_UpdateWindowSurface(window);
}

void Game_Window::Render_Line(Lineseg line, Player player, Uint32 colour) {
    // first convert lineseg positions to be based on the player position
    line.a.x -= player.Get_xPos();
    line.a.y -= player.Get_yPos();
    line.b.x -= player.Get_xPos();
    line.b.y -= player.Get_yPos();

    // then rotate around the player
    float rot = player.Get_Rot();
    float x1 = line.a.x;
    float x2 = line.b.x;
    float y1 = line.a.y;
    float y2 = line.b.y;

    line.a.x = x1 * cos(rot) - y1 * sin(rot);
    line.a.y = x1 * sin(rot) + y1 * cos(rot);
    line.b.x = x2 * cos(rot) - y2 * sin(rot);
    line.b.y = x2 * sin(rot) + y2 * cos(rot);
    // Convert to screenspace
    Vec2 p1, p2;
    p1.x = (int)line.a.x + (winWidth / 2);
    p1.y = (int)line.a.y + (winHeight /2);

    p2.x = (int)line.b.x + (winWidth / 2);
    p2.y = (int)line.b.y + (winHeight / 2);

    // cout<<"("<<p1.x<<","<<p1.y<<") ("<<p2.x<<","<<p2.y<<")"<<endl;

    // Call Draw_Line() to draw the line to screen
    this->Draw_Line(p1, p2, colour);
}

void Game_Window::Render_Player(Player player, Uint32 colour) {
    Vec2 p1, p2, p3;
    int winCenWid, winCenHt;
    winCenWid = winWidth / 2;
    winCenHt = winHeight / 2;

    p1.x = winCenWid;
    p1.y = winCenHt;

    p2.x = winCenWid - 5;
    p2.y = winCenHt + 5;

    p3.x = winCenWid + 5;
    p3.y = winCenHt + 5;

    this->Draw_Line(p1, p2, colour);
    this->Draw_Line(p1, p3, colour);
}

void Game_Window::DDA_Render_Square(Square square, Player player, Uint32 colour) {
    // TODO: implement a DDA approximation for rendering a square. just use a vertical line render for now using Draw_Line()

    float x1, x2, y1, y2, dist1, dist2;
    square.a.x -= player.Get_xPos();
    square.a.y -= player.Get_yPos();
    square.b.x -= player.Get_xPos();
    square.b.y -= player.Get_yPos();

    float rot = player.Get_Rot();
    x1 = square.a.x;
    x2 = square.b.x;
    y1 = square.a.y;
    y2 = square.b.y;

    square.a.x = x1 * cos(rot) - y1 * sin(rot);
    square.a.y = x1 * sin(rot) + y1 * cos(rot);
    square.b.x = x2 * cos(rot) - y2 * sin(rot);
    square.b.y = x2 * sin(rot) + y2 * cos(rot);

    // okay as the distance increases the floor height gets closer to the center of the screen
    int heightCenter = winHeight / 2;
    int widthCenter = winWidth / 2;

    // remember now that all of the distances are in reference to the origin (the player)
    // NOT the player's coordinates

    dist1 = sqrt(pow(square.a.x, 2) + pow(square.a.y, 2));
    dist2 = sqrt(pow(square.b.x, 2) + pow(square.b.y, 2));

    float dDist = dist1 < dist2 ? dist2 - dist1 : dist1 - dist2;
    float dist;

    // also remember that points are given to the screen in reference to the top left corner

    if (square.a.x < square.b.x) {
        dist = dist1;
        for (int x1 = (int)square.a.x; x1 <= square.b.x; x1++) {
            Vec2 a,b;

            float h = square.h / dist;
            a.x = x1;
            b.x = x1;

            a.y = 0;
            b.y = (int)h;

            this->Draw_Line(a, b, colour);

            dist -= dDist;
        }
    } else {
        dist = dist2;
        for (int x1 = (int)square.b.x; x1 <= square.a.x; x1++) {
            Vec2 a,b;

            float h = square.h / dist;
            a.x = x1;
            b.x = x1;

            a.y = 0;
            b.y = (int)h;

            this->Draw_Line(a, b, colour);

            dist -= dDist;
        }
    }
}