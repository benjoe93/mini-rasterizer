#include <stdlib.h>
#include "file_utils.h"
#include "renderer.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr int MAX_COLOR_VALUE = 255;

#define OUT_PATH "../../saved/out.ppm"

int main() {
    const ImgDetails img = {OUT_PATH, MAX_COLOR_VALUE};

    const Color clear_color = {26, 34, 56};

    Color* pixels = malloc(WIDTH * HEIGHT * sizeof(Color));
    if (!pixels)
        return 1;

    ImgBuffer buffer = {
        pixels,
        WIDTH,
        HEIGHT
    };

    // clear screen
    ClearScreen(&buffer, clear_color);

    // draw line middle of the image
    Color line_color = {255, 0, 0};
    DrawHorizontalLine(&buffer, 300, 0, WIDTH, line_color);

    line_color = (Color){0, 255, 0};
    DrawVerticalLine(&buffer, 400, 0, HEIGHT, line_color);

    // update image
    WriteToPpm(&buffer, &img);

    free(pixels);
    pixels = NULL;
    buffer.pixels = NULL;
    return 0;
}