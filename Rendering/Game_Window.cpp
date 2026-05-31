#include <string>
#include "Game_Window.h"

using namespace std;
//using namespace rendering;

Game_Window::Game_Window(const char* title, int width, int height) {
    // define the function
    window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
}