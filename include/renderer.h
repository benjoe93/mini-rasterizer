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
 * @param y0 Start row (exclusive)
 * @param y1 End row (exclusive)
 * @param color Line color
 */
void DrawVerticalLine(ImgBuffer* buffer, const unsigned int x, const unsigned int y0, const unsigned int y1, const Color color);

/**
 * Draw line with Bresenham’s algorithm
 *
 * @param buffer Flat Color array of size width * height
 * @param start Line start coordinates
 * @param end Line end coordinates
 * @param color Line color
 */
void DrawLine(ImgBuffer* buffer, const Vector2 start, const Vector2 end, const Color color);

#endif //MINI_RASTERIZER_RENDERER_H
