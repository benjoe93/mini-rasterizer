// Rasterization pipeline logic
#ifndef MINI_RASTERIZER_RENDERER_H
#define MINI_RASTERIZER_RENDERER_H

#include "types.h"

/**
 * Clear the image buffer with selected color
 *
 * @param buffer Flat Color array of size width * height
 * @param width Image width in pixels
 * @param height Image height in pixels
 * @param color Color to clear image
 */
void ClearScreen(Color *buffer, int width, int height, Color color);

/**
 * Draw a horizontal line across a single row of the buffer
 *
 * @param buffer Flat Color array of size width * height
 * @param width Image width in pixels, used to compute buffer index
 * @param y Row to draw on
 * @param x0 Start column (inclusive)
 * @param x1 End column (inclusive)
 * @param color Color of the line
 */
void DrawHorizontalLine(Color *buffer, int width, int y, int x0, int x1, Color color);

/**
 * Draws a vertical line down a single column of the framebuffer.
 *
 * @param buffer Flat Color array of size width * height
 * @param width Image width in pixels, used to compute buffer index
 * @param x Column to draw on
 * @param y0 Start row (inclusive)
 * @param y1 End row (inclusive)
 * @param color Color of the line
 */
void DrawVerticalLine(Color *buffer, int width, int x, int y0, int y1, Color color);

#endif //MINI_RASTERIZER_RENDERER_H
