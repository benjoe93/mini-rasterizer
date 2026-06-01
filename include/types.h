#ifndef TYPES_H
#define TYPES_H

typedef struct {
    const char* path;
    int width;
    int height;
    int max_val;
}ImgDetails;

typedef struct {
    int R;
    int G;
    int B;
}Color;

#endif
