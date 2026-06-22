#ifndef MINI_RASTERIZER_TYPES_H
#define MINI_RASTERIZER_TYPES_H
#include <stdint.h>

/**
 * RGB Color definition
 */
typedef struct color {
  uint8_t R;
  uint8_t G;
  uint8_t B;
} color_t;

typedef struct point2d {
  unsigned int x;
  unsigned int y;
} point2d_t;

/**
 * Export related image file details
 */
typedef struct img_details {
  const char *path;
  uint8_t max_val;
} img_details_t;

/**
 * Texture buffer details
 */
typedef struct img_buffer {
  color_t *pixels;
  unsigned int width;
  unsigned int height;
} img_buffer_t;

#endif // MINI_RASTERIZER_TYPES_H
