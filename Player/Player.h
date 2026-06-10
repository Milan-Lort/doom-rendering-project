#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL_keyboard.h>

#include "../Types/Types.h"

namespace player {
    // go over all of this later after seeing how others deal with some of these things
    class Player {
        private:
        FltVec2 pos;
        
        float rotation;
        float velocity;

        const bool *key_states = SDL_GetKeyboardState(NULL);
        
        public:

        Player();
        
        void Handle_Input();

        float Get_xPos();

        float Get_yPos();
    };
}

#endif