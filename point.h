#pragma once

typedef struct {
    int x, y;
} Point;

// Makes a new random point between 0->width, 0->height
Point getRandomPoint(int width, int height);

// Moves the point 1px in random direction.
// If new position was outside 0->width or 0->height, returns -1 and does not move the original point
// else returns 0
int movePointRand(Point *p, int width, int height);

// Moves point by dx, dy in x, y respectively
void movePoint(Point *p, int dx, int dy);