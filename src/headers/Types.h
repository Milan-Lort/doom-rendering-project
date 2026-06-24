#ifndef TYPES_H
#define TYPES_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define RENDER_FPS 60

typedef struct Vec2 {
    int x,y;
} Vec2;

typedef struct FltVec2 {
    float x,y;
} FltVec2;

typedef struct Lineseg {
    /*
        Define for now in world space that is arbitrary
        Consier the world space to have a centre at the centre of the screen
        Center is at point (SCREEN_WIDTH/2, SCREEN_HEIGHT/2)
    */
    FltVec2 a, b;
} Lineseg;

typedef struct Wall {
    /*
        a, b define points on the ground, h defines the height of the square
    */
    FltVec2 a, b;
    float h;
} Square;

#endif