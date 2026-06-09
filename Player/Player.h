#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL_keyboard.h>

namespace player {
    // go over all of this later after seeing how others deal with some of these things
    class Player {
        private:
        int velocity;
        int xPos, yPos;

        float rotation;

        const bool *key_states = SDL_GetKeyboardState(NULL);
        
        public:

        Player();
        
        void Handle_Input();

        int Get_xPos();

        int Get_yPos();
    };
}

#endif