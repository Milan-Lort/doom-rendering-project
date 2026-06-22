#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL_keyboard.h>

#include "Types.h"

namespace player {
    // use this class to store player information not used for rendering and perform player actions (again not used for rendering)
    class Player {
        private:
        // Position should be arbitrary world space not screen space
        FltVec2 pos;
        
        float velocity;

        float rotation;
        float rotSpeed;

        const bool *key_states = SDL_GetKeyboardState(NULL);
        
        public:

        Player();
        
        bool Handle_Input();

        float Get_xPos();

        float Get_yPos();

        float Get_Rot();
    };
}

#endif