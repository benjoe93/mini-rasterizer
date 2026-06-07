#ifndef MINI_RASTERIZER_RENDERER_H
#define MINI_RASTERIZER_RENDERER_H
// Rasterization pipeline logic

#include "types.h"
#include "math_utils.h"

/**
 * Clear the image buffer with selected color
 *
 * @param buffer Flat Color array of size width * height
 * @param color Color to clear image
 */
void ClearScreen(ImgBuffer* buffer, const Color color);

void PutPixel(ImgBuffer* buffer, const unsigned int x, const unsigned int y, const Color color);

/**
 * Draw a horizontal line across a single row of the buffer
 *
 * @param buffer Flat Color array of size width * height
 * @param y Row to draw on
 * @param x0 Start column (exclusive)
 * @param x1 End column (exclusive)
 * @param color Line color
 */
void DrawHorizontalLine(ImgBuffer* buffer, const unsigned int y, const unsigned int x0, const unsigned int x1, const Color color);

/**
 * Draws a vertical line down a single column of the framebuffer.
 *
 * @param buffer Flat Color array of size width * height
 * @param x Column to draw on
 * @param y0 Start row (inclusive)
 * @param y1 End row (inclusive)
 * @param color Line color
 */
void DrawVerticalLine(ImgBuffer* buffer, const unsigned int x, const unsigned int y0, const unsigned int y1, const Color color);

/**
 * Draw line with Bresenham’s algorithm
 *
 * @param buffer Flat Color array of size width * height
 * @param x0 Line start x coordinates
 * @param x1 Line end x coordinates
 * @param y0 Line start y coordinates
 * @param y1 Line end y coordinates
 * @param color Line color
 */
void DrawLine(ImgBuffer* buffer, int x0, int x1, int y0, int y1, const Color color);
#endif //MINI_RASTERIZER_RENDERER_H
