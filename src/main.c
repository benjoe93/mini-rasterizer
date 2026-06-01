#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define WIDTH 800
#define HEIGHT 600

#define OUT_PATH = "../../save/out.ppm"

int main() {
    printf("Hello world!\n");


    // open file
    FILE *file = fopen("../../save/out.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // write file
    fprintf(file, "Hello world from C!\n");
    fputs("This is using fputs haha\n", file);

    // close file
    fclose(file);

    return 0;
}