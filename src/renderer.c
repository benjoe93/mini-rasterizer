#include "renderer.h"

void ClearScreen(Color* buffer, const int width, const int height, const Color color) {
    const int length = width * height;
    for (int i = 0; i < length; i++) {
        buffer[i] = color;
    }
}

void DrawHorizontalLine(Color* buffer, const int width, const int y, const int x0, const int x1, const Color color) {
    for (int i = 0; i < x1 - x0; i++) {
        const int index = (y * width) + x0 + i;
        buffer[index] = color;
    }
}

void DrawVerticalLine(Color* buffer, const int width, const int x, const int y0, const int y1, const Color color) {
    const int start_offset = width * y0;
    for (int i = 0; i < y1 - y0; i++) {
        const int index = start_offset + x + (width * i) ;
        buffer[index] = color;
    }
}
