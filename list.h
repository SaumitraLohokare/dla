#pragma once

#include <stdlib.h> // For size_t
#include "point.h"

typedef struct {
    Point *data;
    size_t len;
    size_t cap;
} PointsList;

// Creates a new Points list with given capacity
// NOTE: Please start with non-zero capacity
PointsList newPointsList(size_t capacity);

// Returns point at `i`
// If `i` > length, returns `Point { -1, -1 }`
Point pointAt(PointsList *l, size_t i);

// Pushes point to list
void pushPoint(PointsList *l, Point p);

// Checks if given point touches any point in the list
int pointTouchesOtherPoints(PointsList *l, Point p);

// Moves all points by dx, dy in x, y respectively
void movePoints(PointsList *l, int dx, int dy);

// deletes list
void deleteList(PointsList *l);