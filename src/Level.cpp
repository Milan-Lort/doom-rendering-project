#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "./headers/Level.h"

using namespace level;
using namespace std;

Level::Level(string filename) {
    // load the wall data from filename
    string line;
    ifstream levelData(filename);

    // use a while loop to go through each line in the file and read it into walls
    while (getline(levelData, line)) {
        if (line[0] == '#') {continue;}

        istringstream lineParser(line);
        Wall wall;

        lineParser >> wall.a.x;
        lineParser >> wall.a.y;
        lineParser >> wall.b.x;
        lineParser >> wall.b.y;
        lineParser >> wall.h;

        walls.push_back(wall);
    }
}

vector<Wall> Level::getLevelGeometry() {
    return walls;
}