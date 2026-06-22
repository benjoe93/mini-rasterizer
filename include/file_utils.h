#ifndef MINI_RASTERIZER_FILE_UTILS_H
#define MINI_RASTERIZER_FILE_UTILS_H

#include "types.h"

/**
 * Export the buffer to a PPM image
 *
 * @param buffer Buffer containing per pixel data
 * @param image Export related ImageDetails
 */
void WriteToPpm(const img_buffer_t *buffer, const img_details_t *image);

#endif // MINI_RASTERIZER_FILE_UTILS_H
