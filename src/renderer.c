#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"

void ClearScreen(img_buffer_t* buffer, const color_t color) {
    const size_t length = (size_t)buffer->width * buffer->height;
    for (size_t i = 0; i < length; i++) {
        buffer->pixels[i] = color;
    }
}

void PutPixel(img_buffer_t* buffer, const unsigned int x, const unsigned int y, const color_t color) {
    if (x < buffer->width && y < buffer->height) {
        const size_t index = (size_t)buffer->width * y + x;
        buffer->pixels[index] = color;
    }
}

void DrawHorizontalLine(img_buffer_t* buffer, unsigned int y, unsigned int x0, unsigned int x1, const color_t color) {
    if (y >= buffer->height) {
        fprintf(stderr,
                "Out of bound `y` Coordinate! Value of `y` should be between 0 and "
                "%u.\n",
                buffer->height);
        return;
    }
    if (x0 >= buffer->width) {
        fprintf(stderr,
                "Out of bound `x0` Coordinate! Value of `x0` should be between 0 "
                "and %u.\n",
                buffer->width);
        return;
    }
    if (x1 > buffer->width) {
        fprintf(stderr,
                "Out of bound `x1` Coordinate! Value of `x1` should be between 0 "
                "and %u.\n",
                buffer->width);
        return;
    }
    if (x0 > x1) {
        unsigned int temp = x1;
        x1 = x0;
        x0 = temp;

    }

    for (size_t i = 0; i < x1 - x0; i++) {
        size_t index = ((size_t)y * buffer->width) + x0 + i;
        buffer->pixels[index] = color;
    }
}

void DrawVerticalLine(img_buffer_t* buffer, unsigned int x, unsigned int y0, unsigned int y1, const color_t color) {
    if (x >= buffer->width) {
        fprintf(stderr,
                "Out of bound `x` Coordinate! Value of `x` should be between 0 and "
                "%u.\n",
                buffer->width);
        return;
    }
    if (y0 >= buffer->height) {
        fprintf(stderr,
                "Out of bound `y0` Coordinate! Value of `y0` should be between 0 "
                "and %u.\n",
                buffer->height);
        return;
    }
    if (y1 > buffer->height) {
        fprintf(stderr,
                "Out of bound `y1` Coordinate! Value of `y1` should be between 0 "
                "and %u.\n",
                buffer->height);
        return;
    }
    if (y0 > y1) {
        unsigned int temp = y1;
        y1 = y0;
        y0 = temp;
    }

    const size_t start_offset = (size_t)buffer->width * y0;
    for (size_t i = 0; i < y1 - y0; i++) {
        size_t index = start_offset + x + ((size_t)buffer->width * i);
        buffer->pixels[index] = color;
    }
}

static void DrawLineH(img_buffer_t* buffer, int x0, int x1, int y0, int y1, const color_t color) {
    if (x0 > x1) {
        int x_temp = x0;
        x0 = x1;
        x1 = x_temp;

        int y_temp = y0;
        y0 = y1;
        y1 = y_temp;
    }

    int dx = x1 - x0;
    int dy = y1 - y0;

    int dir = (dy < 0) ? -1 : 1;
    dy *= dir;

    if (dx != 0) {
        int y = y0;
        int p = 2 * dy - dx;
        for (int i = 0; i < dx + 1; i++) {
            PutPixel(buffer, (unsigned int)(x0 + i), (unsigned int)y, color);
            if (p >= 0) {
                y += dir;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
        }
    }
}

static void DrawLineV(img_buffer_t* buffer, int x0, int x1, int y0, int y1, const color_t color) {
    if (y0 > y1) {
        int x_temp = x0;
        x0 = x1;
        x1 = x_temp;

        int y_temp = y0;
        y0 = y1;
        y1 = y_temp;
    }

    int dx = x1 - x0;
    int dy = y1 - y0;

    int dir = (dx < 0) ? -1 : 1;
    dx *= dir;

    if (dy != 0) {
        int x = x0;
        int p = 2 * dx - dy;
        for (int i = 0; i < dy + 1; i++) {
            PutPixel(buffer, (unsigned int)x, (unsigned int)(y0 + i), color);
            if (p >= 0) {
                x += dir;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
        }
    }
}

void DrawLine(img_buffer_t* buffer, int x0, int y0, int x1, int y1, const color_t color) {
    if (abs(x1 - x0) > abs(y1 - y0)) {
        DrawLineH(buffer, x0, x1, y0, y1, color);
    }
    else {
        DrawLineV(buffer, x0, x1, y0, y1, color);
    }
}

void DrawRectangle(img_buffer_t* buffer, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, bool outline, bool fill, const color_t outline_color, const color_t fill_color) {
    // Guard point positions
    unsigned int left_x, right_x, top_y, bottom_y;
    left_x = x0 < x1 ? x0 : x1;
    right_x = x0 < x1 ? x1 : x0;

    top_y = y0 < y1 ? y0 : y1;
    bottom_y = y0 < y1 ? y1 : y0;

    // Draw fill
    if (fill) {
        for (unsigned int y = top_y; y <= bottom_y; y++) {
            DrawHorizontalLine(buffer, y, left_x, right_x+1, fill_color);
        }
    }

    // Draw outline
    if (outline) {
        DrawHorizontalLine(buffer, top_y, left_x, right_x+1, outline_color);
        DrawHorizontalLine(buffer, bottom_y, left_x, right_x+1, outline_color);
        DrawVerticalLine(buffer, left_x, top_y, bottom_y+1, outline_color);
        DrawVerticalLine(buffer, right_x, top_y, bottom_y+1, outline_color);
    }
}
