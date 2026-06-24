#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include "Types.h"
#include "Player.h"

using namespace std;
using namespace player;

namespace rendering {

class Game_Window {
    private:
    int winWidth;
    int winHeight;

    SDL_Renderer* renderer;
    SDL_Surface* surf;
    SDL_Surface* winSurf;
    
    void Set_Px(int x, int y, Uint32 colour);

    public:
    SDL_Window* window;

    Game_Window(const char* title, int width, int height, SDL_Surface* drawSurf);

    void Draw_Rectangle(int x1, int y1, int x2, int y2, Uint32 colour);

    // mostly use draw_line and render_line for testing
    // rewrite them in a more cohesive manner when moving up to polygons
    void Draw_Line(Vec2 p1, Vec2 p2, Uint32 colour);

    void Render_Line(Lineseg line, Player player, Uint32 colour);

    void Render_Player(Player player, Uint32 colour);

    void DDA_Render_Square(Wall square, Player player, Uint32 colour);

    void Update_Window();

    void Clear_Surf(Uint32 colour);
};

}

#endif