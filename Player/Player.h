#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL_keyboard.h>

namespace player {
    // go over all of this later after seeing how others deal with some of these things
    class Player {
        private:
        int velocity;
        int movDir[2];

        const bool *key_states = SDL_GetKeyboardState(NULL);
        
        public:
        int position[2];
        int faceDir[2];

        Player();
        
        void Handle_Input();
    };
}

#endif