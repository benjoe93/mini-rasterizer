#ifndef MINI_RASTERIZER_RENDERER_H
#define MINI_RASTERIZER_RENDERER_H
// Rasterization pipeline logic

#include "types.h"

/**
 * Clear the image buffer with selected color
 *
 * @param buffer Flat Color array of size width * height
 * @param color Color to clear image
 */
void ClearScreen(img_buffer_t* buffer, color_t color);

void PutPixel(img_buffer_t* buffer, const unsigned int x, const unsigned int y, color_t color);

/**
 * Draw a horizontal line across a single row of the buffer
 *
 * @param buffer Flat Color array of size width * height
 * @param y Row to draw on
 * @param x0 Start column
 * @param x1 End column (exclusive)
 * @param color Line color
 */
void DrawHorizontalLine(img_buffer_t* buffer, unsigned int y, unsigned int x0, unsigned int x1, color_t color);

/**
 * Draws a vertical line down a single column of the framebuffer.
 *
 * @param buffer Flat Color array of size width * height
 * @param x Column to draw on
 * @param y0 Start row
 * @param y1 End row (inclusive)
 * @param color Line color
 */
void DrawVerticalLine(img_buffer_t* buffer, unsigned int x, unsigned int y0, unsigned int y1, color_t color);

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
void DrawLine(img_buffer_t* buffer, int x0, int x1, int y0, int y1, color_t color);

/**
 *
 * @param buffer Flat Color array of size width * height
 * @param top_left Top left Point2D coordinates
 * @param bottom_right Bottom Point2D coordinates
 * @param outline Switch to draw shape outline
 * @param fill Switch to fill shape
 * @param outline_color Color of the outline
 * @param fill_color Color of the fill
 */
void DrawRectangle(img_buffer_t* buffer, point2d_t top_left, point2d_t bottom_right, bool outline, bool fill, color_t outline_color, color_t fill_color);
#endif // MINI_RASTERIZER_RENDERER_H
