#include "renderer.h"

#include <stdio.h>

void ClearScreen(ImgBuffer* buffer, const Color color) {
    const unsigned int length = buffer->width * buffer->height;
    for (size_t i = 0; i < length; i++) {
        buffer->pixels[i] = color;
    }
}

void DrawHorizontalLine(ImgBuffer* buffer, const unsigned int y, const unsigned int x0, const unsigned int x1, const Color color) {
    if (y < 0 || y > buffer->height) {
        fprintf(stderr,"Out of bound `y` Coordinate! Value of `y` should be between 0 and %u.\n", buffer->height);
        return;
    }
    if (x0 < 0 || x0 > buffer->width) {
        fprintf(stderr,"Out of bound `x0` Coordinate! Value of `x0` should be between 0 and %u.\n", buffer->width);
        return;
    }
    if (x1 < 0 || x1 > buffer->width) {
        fprintf(stderr,"Out of bound `x1` Coordinate! Value of `x1` should be between 0 and %u.\n", buffer->width);
        return;
    }

    for (unsigned int i = 0; i < x1 - x0; i++) {
        const unsigned int index = (y * buffer->width) + x0 + i;
        buffer->pixels[index] = color;
    }
}

void DrawVerticalLine(ImgBuffer* buffer, const unsigned int x, const unsigned int y0, const unsigned int y1, const Color color) {
    if (x < 0 || x > buffer->width) {
        fprintf(stderr,"Out of bound `x` Coordinate! Value of `x` should be between 0 and %u.\n", buffer->width);
        return;
    }
    if (y0 < 0 || y0 > buffer->height) {
        fprintf(stderr,"Out of bound `y0` Coordinate! Value of `y0` should be between 0 and %u.\n", buffer->height);
        return;
    }
    if (y1 < 0 || y1 > buffer->height) {
        fprintf(stderr,"Out of bound `y1` Coordinate! Value of `y1` should be between 0 and %u.\n", buffer->height);
        return;
    }

    const unsigned int start_offset = buffer->width * y0;
    for (unsigned int i = 0; i < y1 - y0; i++) {
        const unsigned int index = start_offset + x + (buffer->width * i);
        buffer->pixels[index] = color;
    }
}

/* TODO: Implement Bresenham's line algorithm */
void DrawLine(ImgBuffer* buffer, const Vector2 start, const Vector2 end, const Color color) {}
