#include "file_utils.h"
#include "renderer.h"
#include "types.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR_VALUE 255

#define OUT_PATH "../saved/out.ppm"

int main() {
    const img_details_t img = {OUT_PATH, MAX_COLOR_VALUE};

    const color_t clear_color = {26, 34, 56};

    color_t *pixels = malloc(WIDTH * HEIGHT * sizeof(color_t));
    if (!pixels) { return 1; }

    img_buffer_t buffer = {pixels, WIDTH, HEIGHT};

    // clear screen
    ClearScreen(&buffer, clear_color);

    // draw line middle of the image
    color_t line_color = {255, 0, 0};
    DrawHorizontalLine(&buffer, 300, 0, WIDTH, line_color);

    DrawVerticalLine(&buffer, 400, 0, HEIGHT, line_color);

    line_color = (color_t){255, 255, 0};
    DrawLine(&buffer, 790, 10, 10, 590, line_color);

    line_color = (color_t){0, 255, 0};
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

    // Draw axis-aligned rectangle
    line_color = (color_t){0, 255, 125};
    color_t fill_color = {0, 125, 255};
    point2d_t p0 = {.x = 700, .y = 550};
    point2d_t p1 = {.x = 500, .y = 350};
    DrawRectangle(&buffer, p0, p1, true, true, line_color, fill_color);

    // update image
    WriteToPpm(&buffer, &img);

    free(pixels);
    pixels = NULL;
    buffer.pixels = NULL;
    return 0;
}
