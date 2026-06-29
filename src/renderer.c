#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"

void ClearScreen(img_buffer_t* buffer, const color_t color) {
    const size_t length = (size_t)buffer->width * buffer->height;
    for (size_t i = 0; i < length; i++) {
        buffer->pixels[i] = color;
    }
}

void PutPixel(img_buffer_t* buffer, int32_t x, int32_t y, const color_t color) {
    if (x < 0 || y < 0 || x >= (int32_t)buffer->width || y >= (int32_t)buffer->height) { return; }
    buffer->pixels[(size_t)y * buffer->width + x] = color;
}

void DrawHorizontalLine(img_buffer_t* buffer, int32_t y, int32_t x0, int32_t x1, const color_t color) {
    if (y < 0 || y >= (int32_t)buffer->height) { return; }

    if (x0 > x1) {
        int32_t temp = x0;
        x0 = x1;
        x1 = temp;
    }

    // Clamp to buffer bounds
    if (x0 < 0) { x0 = 0; }
    if (x1 >= (int32_t)buffer->width) { x1 = (int32_t)buffer->width - 1; }
    if (x0 > x1) { return; }

    for (int32_t i = x0; i <= x1; i++) {
        buffer->pixels[(size_t)y * buffer->width + i] = color;
    }
}

void DrawVerticalLine(img_buffer_t* buffer, int32_t x, int32_t y0, int32_t y1, const color_t color) {
    if (x < 0 || x >= (int32_t)buffer->width) { return; }

    if (y0 > y1) {
        int32_t temp = y0;
        y0 = y1;
        y1 = temp;
    }

    // Clamp to buffer bounds
    if (y0 < 0) { y0 = 0; }
    if (y1 >= (int32_t)buffer->height) { y1 = (int32_t)buffer->height - 1; }
    if (y0 > y1) { return; }

    for (int32_t i = y0; i <= y1; i++) {
        buffer->pixels[(size_t)i * buffer->width + x] = color;
    }
}

static void DrawLineH(img_buffer_t* buffer, int32_t x0, int32_t x1, int32_t y0, int32_t y1, const color_t color) {
    if (x0 > x1) {
        int32_t x_temp = x0; x0 = x1; x1 = x_temp;
        int32_t y_temp = y0; y0 = y1; y1 = y_temp;
    }

    int32_t dx = x1 - x0;
    int32_t dy = y1 - y0;

    int32_t dir = (dy < 0) ? -1 : 1;
    dy *= dir;

    if (dx != 0) {
        int32_t y = y0;
        int32_t p = 2 * dy - dx;
        for (int32_t i = 0; i < dx + 1; i++) {
            PutPixel(buffer, x0 + i, y, color);
            if (p >= 0) {
                y += dir;
                p = p - 2 * dx;
            }
            p = p + 2 * dy;
        }
    }
}

static void DrawLineV(img_buffer_t* buffer, int32_t x0, int32_t x1, int32_t y0, int32_t y1, const color_t color) {
    if (y0 > y1) {
        int32_t x_temp = x0; x0 = x1; x1 = x_temp;
        int32_t y_temp = y0; y0 = y1; y1 = y_temp;
    }

    int32_t dx = x1 - x0;
    int32_t dy = y1 - y0;

    int32_t dir = (dx < 0) ? -1 : 1;
    dx *= dir;

    if (dy != 0) {
        int32_t x = x0;
        int32_t p = 2 * dx - dy;
        for (int32_t i = 0; i < dy + 1; i++) {
            PutPixel(buffer, x, y0 + i, color);
            if (p >= 0) {
                x += dir;
                p = p - 2 * dy;
            }
            p = p + 2 * dx;
        }
    }
}

void DrawLine(img_buffer_t* buffer, int32_t x0, int32_t y0, int32_t x1, int32_t y1, const color_t color) {
    if (abs(x1 - x0) > abs(y1 - y0)) {
        DrawLineH(buffer, x0, x1, y0, y1, color);
    } else {
        DrawLineV(buffer, x0, x1, y0, y1, color);
    }
}

void DrawRectangle(img_buffer_t* buffer, int32_t x0, int32_t y0, int32_t x1, int32_t y1, bool outline, bool fill, const color_t outline_color, const color_t fill_color) {
    int32_t left_x   = x0 < x1 ? x0 : x1;
    int32_t right_x  = x0 < x1 ? x1 : x0;
    int32_t top_y    = y0 < y1 ? y0 : y1;
    int32_t bottom_y = y0 < y1 ? y1 : y0;

    if (fill) {
        for (int32_t y = top_y; y <= bottom_y; y++) {
            DrawHorizontalLine(buffer, y, left_x, right_x, fill_color);
        }
    }

    if (outline) {
        DrawHorizontalLine(buffer, top_y,    left_x, right_x, outline_color);
        DrawHorizontalLine(buffer, bottom_y, left_x, right_x, outline_color);
        DrawVerticalLine(buffer, left_x,  top_y, bottom_y, outline_color);
        DrawVerticalLine(buffer, right_x, top_y, bottom_y, outline_color);
    }
}

void DrawCircle(img_buffer_t* buffer, int32_t cx, int32_t cy, int32_t radius, bool outline, bool fill, const color_t outline_color, const color_t fill_color) {
    int32_t x = 0;
    int32_t y = radius;
    int32_t d = 3 - 2 * radius;

    while (y >= x) {
        if (fill) {
            DrawHorizontalLine(buffer, cy + y, cx - x, cx + x, fill_color);
            DrawHorizontalLine(buffer, cy - y, cx - x, cx + x, fill_color);
            DrawHorizontalLine(buffer, cy + x, cx - y, cx + y, fill_color);
            DrawHorizontalLine(buffer, cy - x, cx - y, cx + y, fill_color);
        }

        if (outline) {
            PutPixel(buffer, cx + x, cy + y, outline_color);
            PutPixel(buffer, cx - x, cy + y, outline_color);
            PutPixel(buffer, cx + x, cy - y, outline_color);
            PutPixel(buffer, cx - x, cy - y, outline_color);
            PutPixel(buffer, cx + y, cy + x, outline_color);
            PutPixel(buffer, cx - y, cy + x, outline_color);
            PutPixel(buffer, cx + y, cy - x, outline_color);
            PutPixel(buffer, cx - y, cy - x, outline_color);
        }

        if (d > 0) {
            y--;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
        x++;
    }
}