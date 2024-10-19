#include "point.h"

#include <stdlib.h>

Point getRandomPoint(int width, int height) {
    Point p;
    p.x = rand() % width;
    p.y = rand() % height;
    return p;
}

int movePointRand(Point *p, int width, int height) {
    int dir = rand() % 4;
    if (dir == 0 && p->y - 1 >= 0) {
        // Up
        p->y -= 1;
        return 0;
    } else if (dir == 1 && p->y + 1 <= height) {
        // Down
        p->y += 1;
        return 0;
    } else if (dir == 2 && p->x - 1 >= 0) {
        // Left
        p->x -= 1;
        return 0;
    } else if (dir == 3 && p->x + 1 <= width) {
        // Right
        p->x += 1;
        return 0;
    }

    return -1;
}

void movePoint(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}