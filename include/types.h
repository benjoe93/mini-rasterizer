#ifndef MINI_RASTERIZER_TYPES_H
#define MINI_RASTERIZER_TYPES_H
#include <stdint.h>

/**
 * RGB Color definition
 */
typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} color_t;

/**
 * Export related image file details
 */
typedef struct {
  const char *path;
  uint8_t max_val;
} img_details_t;

/**
 * Texture buffer details
 */
typedef struct {
  color_t *pixels;
  uint32_t width;
  uint32_t height;
} img_buffer_t;

typedef struct {
  img_buffer_t* buffer;
  img_details_t* img;
} screenshot_ctx_t;

#endif // MINI_RASTERIZER_TYPES_H
