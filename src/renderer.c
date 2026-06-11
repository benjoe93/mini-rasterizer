#include <math.h>
#include <stdio.h>

#include "renderer.h"

#include "../external/minifb-src/src/windows/WindowData_Win.h"

void ClearScreen(ImgBuffer* buffer, const Color color) {
    const unsigned int length = buffer->width * buffer->height;
    for (size_t i = 0; i < length; i++) {
        buffer->pixels[i] = color;
    }
}

void PutPixel(ImgBuffer* buffer, const unsigned int x, const unsigned int y,
              const Color color) {
    if (x < buffer->width && y < buffer->height) {
        const unsigned int index = buffer->width * y + x;
        buffer->pixels[index] = color;
    }
}

void DrawHorizontalLine(ImgBuffer* buffer, const unsigned int y,
                        const unsigned int x0, const unsigned int x1,
                        const Color color) {
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

    for (unsigned int i = 0; i < x1 - x0; i++) {
        const unsigned int index = (y * buffer->width) + x0 + i;
        buffer->pixels[index] = color;
    }
}

void DrawVerticalLine(ImgBuffer* buffer, const unsigned int x, const unsigned int y0, const unsigned int y1, const Color color) {
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

    const unsigned int start_offset = buffer->width * y0;
    for (unsigned int i = 0; i < y1 - y0; i++) {
        const unsigned int index = start_offset + x + (buffer->width * i);
        buffer->pixels[index] = color;
    }
}

static void DrawLineH(ImgBuffer* buffer, int x0, int x1, int y0, int y1, const Color color) {
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
            PutPixel(buffer, x0 + i, y, color);
            if (p >= 0) {
                y += dir;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
        }
    }
}

static void DrawLineV(ImgBuffer* buffer, int x0, int x1, int y0, int y1, const Color color) {
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
            PutPixel(buffer, x, y0 + i, color);
            if (p >= 0) {
                x += dir;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
        }
    }
}

void DrawLine(ImgBuffer* buffer, int x0, int x1, int y0, int y1, const Color color) {
    if (abs(x1 - x0) > abs(y1 - y0)) {
        DrawLineH(buffer, x0, x1, y0, y1, color);
    }
    else {
        DrawLineV(buffer, x0, x1, y0, y1, color);
    }
}

void DrawRectangle(ImgBuffer* buffer, Point2D p0, Point2D p1, Point2D p2, Point2D p3, const Color color) {
    int min_y = min(p0.y, p1.y);
}
