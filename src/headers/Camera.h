#ifndef CAMERA_H
#define CAMERA_H

#include <SDL3/SDL.h>

#include "Types.h"

namespace rendering {

class Camera {
    private:
    FltVec2 pos;
        
    float velocity;
    float rotation;
    float rotSpeed;
    
    const bool *key_states = SDL_GetKeyboardState(NULL);
    SDL_Surface* drawSurf;
    public:

    Camera(SDL_Surface* surf);

    void Handle_Movement(float deltaTime);

    void Set_Px(Vec2 p, Uint32 colour);

    void Render_Line(Vec2 p1, Vec2 p2, Uint32 colour);

    void Wireframe_Render_Wall(Wall wall, Uint32 colour);
};

}

#endif