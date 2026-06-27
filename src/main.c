#include "file_utils.h"
#include "renderer.h"
#include "types.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR_VALUE 255

#define OUT_PATH OUTPUT_DIR "/out.ppm"

int main(void) {
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

    // Draw astrix
    line_color = (color_t){0, 255, 0};
    DrawLine(&buffer,  75, 150, 325, 150, line_color);
    DrawLine(&buffer,  85, 102, 315, 198, line_color);
    DrawLine(&buffer, 112,  62, 288, 238, line_color);
    DrawLine(&buffer, 152,  35, 248, 265, line_color);
    DrawLine(&buffer, 200,  25, 200, 275, line_color);
    DrawLine(&buffer, 248,  35, 152, 265, line_color);
    DrawLine(&buffer, 288,  62, 112, 238, line_color);
    DrawLine(&buffer, 315, 102,  85, 198, line_color);

    // Draw axis-aligned rectangle
    line_color = (color_t){0, 255, 125};
    color_t fill_color = {0, 125, 255};
    DrawRectangle(&buffer, 700, 550, 500, 350, true, true, line_color, fill_color);

    // Draw circle
    DrawCircle(&buffer, 200, 450, 100, true, true, line_color, fill_color);

    // update image
    WriteToPpm(&buffer, &img);

    free(pixels);
    pixels = NULL;
    buffer.pixels = NULL;
    return 0;
}
