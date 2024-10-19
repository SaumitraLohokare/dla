#include "list.h"

#include <stdio.h>

PointsList newPointsList(size_t capacity) {
    PointsList list;
    list.data = (Point *)malloc(capacity * sizeof(Point));

    if (list.data == NULL) {
        printf("Failed to allocate points list.\n");
    }
    
    list.len = 0;
    list.cap = capacity;
    return list;
}

Point pointAt(PointsList *l, size_t i) {
    if (i < l->len) {
        return l->data[i];
    }

    Point p;
    p.x = -1;
    p.y = -1;
    return p;
}

void pushPoint(PointsList *l, Point p) {
    if (l->len == l->cap) {
        l->data = (Point *)realloc(l->data, l->cap * 2 * sizeof(Point));
        l->cap *= 2;

        if (l->data == NULL) {
            printf("ERROR: Failed to allocate more data in list.\n");
        }
    }

    l->data[l->len] = p;
    l->len += 1;
}

int pointTouchesOtherPoints(PointsList *l, Point p) {
    for (size_t i = 0; i < l->len; i++) {
        Point t = pointAt(l, i);
        int horizontal = ((t.x == p.x - 1 || t.x == p.x + 1) && t.y == p.y);
        int vertical = ((t.y == p.y - 1 || t.y == p.y + 1) && t.x == p.x);

        if (horizontal || vertical) {
            return 1;
        }
    }
    return 0;
}

void movePoints(PointsList *l, int dx, int dy) {
    for (size_t i = 0; i < l->len; i++) {
        movePoint(&l->data[i], dx, dy);
    }
}

void deleteList(PointsList *l) {
    free(l->data);
}