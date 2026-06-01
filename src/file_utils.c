// File handling utilities

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <file_utils.h>

void WriteToPpm(const ImgDetails* image, const Color* colors) {
    // open file
    FILE *file = fopen(image->path, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // write file
    fputs("P3\n", file); // ppm header
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "%d\n", image->max_val);

    // pixels
    for (int i = 0; i < image->height * image->width; i++) {
        fprintf(file, "%d %d %d\n", colors[i].R, colors[i].G, colors[i].B);
    }

    // close file
    fclose(file);
}
