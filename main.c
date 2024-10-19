#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define OLIVEC_IMPLEMENTATION
#include "olive.c"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "point.h"
#include "list.h"

// Edit these parameters to vary results
#define DEBUG 1                     // Print Debug Info
#define STARTING_CANVAS_SIZE 10     // Initial canvas size (SIZExSIZE pixels)
#define SIZE_INC_PER_STEP 10        // Pixels to add to canvas width and height per DLA step
#define DLA_STEPS 9                 // DLA steps to perform

// For some reason olive.c works with ABGR and not RGBA
#define BLACK 0xFF000000

int pointsToGenerate(int canvas_size, int generated_points) {
    return (canvas_size * canvas_size / 4) - generated_points; 
}

void dla_step(PointsList *list, int points_to_generate, int canvas_size) {
    for (size_t i = 0; i < points_to_generate; i++) {
        // Generate another point
        Point p = getRandomPoint(canvas_size, canvas_size);

        // Check if point is touching another point
        while (!pointTouchesOtherPoints(list, p)) {
            // Move point until it touches other points
            movePointRand(&p, canvas_size, canvas_size);
        }

        pushPoint(list, p);
    }

    if (DEBUG) printf("Added %d points.\n", points_to_generate);
}

int dla(PointsList *list, int steps) {
    int canvas_size = STARTING_CANVAS_SIZE;

    // Place initial random point
    Point first = getRandomPoint(canvas_size, canvas_size);
    pushPoint(list, first);

    for (int i = 0; i < steps; i++) {
        if (DEBUG) printf("Step %d: ", i + 1);
        // Perform one step
        dla_step(list, pointsToGenerate(canvas_size, list->len), canvas_size);
        // Increase our canvas size
        canvas_size += SIZE_INC_PER_STEP;
        // Move points to center
        movePoints(list, SIZE_INC_PER_STEP / 2, SIZE_INC_PER_STEP / 2);
    }

    if (DEBUG) printf("\nDLA Completed.\n");

    return canvas_size;
}

int main(void) {
    srand(time(NULL));

    PointsList list = newPointsList(1000);
    
    clock_t t; 
    t = clock(); 

    int size = dla(&list, DLA_STEPS);
    
    t = clock() - t; 

    if (DEBUG) printf("Allocating canvas of size: %dx%d pixels.\n", size, size);
    uint32_t *pixels = malloc(size * size * sizeof(uint32_t));
    if (pixels == NULL) {
        printf("Failed to allocate canvas.\n");
        return 1;
    }
    Olivec_Canvas oc = olivec_canvas(pixels, size, size, size);

    olivec_fill(oc, 0xFFFFFFFF);

    if (DEBUG) printf("Coloring pixes\n");
    for (size_t i = 0; i < list.len; i++) {
        Point p = pointAt(&list, i);
        olivec_rect(oc, p.x, p.y, 1, 1, BLACK);
    }
    deleteList(&list);

    const char *filepath = "result.png";
    if (!stbi_write_png(filepath, size, size, 4, pixels, sizeof(uint32_t) * size)) {
       fprintf(stderr, "ERROR: Failed to write image.\n");
       return 1; 
    }
    if (DEBUG) printf("Saved image to result.png\n");

    printf("\n---------------\nDLA Results\n---------------\n");
    printf("Image Size: %dx%d pixels\n", size, size);
    printf("Points Generated: %d\n", list.len);
    printf("Time Taken: %fs\n\n", ((float)t)/CLOCKS_PER_SEC);

    return 0;
}