#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

#include "Types.h"

using namespace std;

namespace level {

class Level {
    private:

    vector<Wall> walls;

    public:

    Level(string filename);

    vector<Wall> getLevelGeometry();
};

}

#endif