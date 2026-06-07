#include <stdlib.h>
#include "file_utils.h"
#include "renderer.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR_VALUE 255

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

    DrawVerticalLine(&buffer, 400, 0, HEIGHT, line_color);

    line_color = (Color){255, 255, 0};
    DrawLine(&buffer, 790, 10, 10, 590, line_color);

    line_color = (Color){0, 255, 0};
    DrawLine(&buffer, 60, 340, 150, 150, line_color);
    DrawLine(&buffer, 65, 335, 114, 186, line_color);
    DrawLine(&buffer, 79, 321, 80, 220, line_color);
    DrawLine(&buffer, 101, 299, 51, 249, line_color);
    DrawLine(&buffer, 130, 270, 29, 271, line_color);
    DrawLine(&buffer, 164, 236, 15, 285, line_color);
    DrawLine(&buffer, 200, 200, 10, 290, line_color);
    DrawLine(&buffer, 164, 236, 285, 15, line_color);
    DrawLine(&buffer, 130, 270, 271, 29, line_color);
    DrawLine(&buffer, 101, 299, 249, 51, line_color);
    DrawLine(&buffer, 79, 321, 220, 80, line_color);
    DrawLine(&buffer, 65, 335, 186, 114, line_color);


    // update image
    WriteToPpm(&buffer, &img);

    free(pixels);
    pixels = NULL;
    buffer.pixels = NULL;
    return 0;
}