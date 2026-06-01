#define _CRT_SECURE_NO_WARNINGS
#include <file_utils.h>
#include <stdlib.h>
#include <types.h>

#define WIDTH 800
#define HEIGHT 600
#define MAXVAL 255

#define OUT_PATH "../../saved/out.ppm"

int main() {
    const ImgDetails img = {OUT_PATH, WIDTH, HEIGHT, MAXVAL};

    // clear screen
    Color clear_color = {26, 34, 56};
    Color *colors = malloc(WIDTH * HEIGHT * sizeof(Color));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        colors[i] = clear_color;
    }

    // draw line middle of the image
    int target_y = HEIGHT / 2;
    Color line_color = {255, 0, 0};

    for (int x = 0; x < WIDTH; x++) {
        const int index = x + (target_y * WIDTH);
        colors[index] = line_color;
    }

    // update image
    WriteToPpm(&img, colors);
    return 0;
}