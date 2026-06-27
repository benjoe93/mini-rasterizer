#ifndef MINI_RASTERIZER_RENDERER_H
#define MINI_RASTERIZER_RENDERER_H
// Rasterization pipeline logic

#include "types.h"
#include <stdbool.h>

/**
 * Clear the image buffer with selected color
 *
 * @param buffer Flat Color array of size width * height
 * @param color Color to clear image
 */
void ClearScreen(img_buffer_t* buffer, const color_t color);


void PutPixel(img_buffer_t* buffer, const unsigned int x, const unsigned int y, const color_t color);

/**
 * Draw a horizontal line across a single row of the buffer
 *
 * @param buffer Flat Color array of size width * height
 * @param y Row to draw on
 * @param x0 Start column
 * @param x1 End column (exclusive)
 * @param color Line color
 */
void DrawHorizontalLine(img_buffer_t* buffer, unsigned int y, unsigned int x0, unsigned int x1, const color_t color);

/**
 * Draws a vertical line down a single column of the framebuffer.
 *
 * @param buffer Flat Color array of size width * height
 * @param x Column to draw on
 * @param y0 Start row
 * @param y1 End row (exclusive)
 * @param color Line color
 */
void DrawVerticalLine(img_buffer_t* buffer, unsigned int x, unsigned int y0, unsigned int y1, const color_t color);

/**
 * Draw line with Bresenham’s algorithm
 *
 * @param buffer Flat Color array of size width * height
 * @param x0 Line start x coordinates
 * @param y0 Line start y coordinates
 * @param x1 Line end x coordinates
 * @param y1 Line end y coordinates
 * @param color Line color
 */
void DrawLine(img_buffer_t* buffer, int x0, int y0, int x1, int y1, const color_t color);

/**
 *
 * @param buffer Flat Color array of size width * height
 * @param x0 first corner x coordinate
 * @param y0 first corner y coordinate
 * @param x1 second corner x coordinate
 * @param y1 second corner y coordinate
 * @param outline Switch to draw shape outline
 * @param fill Switch to fill shape
 * @param outline_color Color of the outline
 * @param fill_color Color of the fill
 */
void DrawRectangle(img_buffer_t* buffer, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, bool outline, bool fill, const color_t outline_color, const color_t fill_color);

/**
 *
 * @param buffer Flat Color array of size width * height
 * @param cx center x-coordinate
 * @param cy center y-coordinate
 * @param radius radius of circle
 * @param outline switch to draw outline
 * @param fill switch to fill shape
 * @param outline_color  color of the outline
 * @param fill_color color of the fill
 */
void DrawCircle(img_buffer_t* buffer, unsigned int cx, unsigned int cy, unsigned int radius, bool outline, bool fill, const color_t outline_color, const color_t fill_color);
#endif // MINI_RASTERIZER_RENDERER_H
