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

    Camera(SDL_Surface* drawSurf);

    float Get_xPos();

    float Get_yPos();
    
    float Get_Rot();

    void Handle_Movement();
};

}

#endif