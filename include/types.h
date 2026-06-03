#ifndef MINI_RASTERIZER_TYPES_H
#define MINI_RASTERIZER_TYPES_H
#include <stdint.h>

/**
 * RGB Color definition
 */
typedef struct Color {
    uint8_t R;
    uint8_t G;
    uint8_t B;
} Color;

/**
 * Export related image file details
 */
typedef struct ImgDetails {
    const char* path;
    uint8_t max_val;
} ImgDetails;

/**
 * Texture buffer details
 */
typedef struct ImgBuffer {
    Color* pixels;
    unsigned int width;
    unsigned int height;
} ImgBuffer;

#endif // MINI_RASTERIZER_TYPES_H
