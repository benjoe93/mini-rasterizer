#define _CRT_SECURE_NO_WARNINGS
#include <file_utils.h>
#include <stdlib.h>
#include <types.h>
#include "renderer.h"

#define WIDTH 800
#define HEIGHT 600
#define MAXVAL 255

#define OUT_PATH "../../saved/out.ppm"

int main() {
    const ImgDetails img = {OUT_PATH, WIDTH, HEIGHT, MAXVAL};

    const Color clear_color = {26, 34, 56};
    Color *buffer = malloc(WIDTH * HEIGHT * sizeof(Color));

    // clear screen
    ClearScreen(buffer, WIDTH, HEIGHT, clear_color);

    // draw line middle of the image
    Color line_color = {255, 0, 0};
    DrawHorizontalLine(buffer, WIDTH, 4, 0, WIDTH, line_color);

    line_color = (Color){0, 255, 0};
    DrawVerticalLine(buffer, WIDTH, 4, 0, HEIGHT, line_color);

    // update image
    WriteToPpm(&img, buffer);
    return 0;
}