#ifndef MINI_RASTERIZER_RENDERER_H
#define MINI_RASTERIZER_RENDERER_H
// Rasterization pipeline logic

#include "math_utils.h"
#include "types.h"
#include <stdbool.h>

/**
 * Clear the image buffer with selected color
 *
 * @param buffer Flat Color array of size width * height
 * @param color Color to clear image
 */
void ClearScreen(img_buffer_t* buffer, const color_t color);

/**
 * Write a single pixel to the buffer, no-op if coordinates are out of bounds
 *
 * @param buffer Flat Color array of size width * height
 * @param x Column (may be negative — will be rejected)
 * @param y Row (may be negative — will be rejected)
 * @param color Pixel color
 */
void PutPixel(img_buffer_t* buffer, int32_t x, int32_t y, const color_t color);

/**
 * Draw a horizontal line across a single row of the buffer.
 * Coordinates are clamped to the buffer bounds, so out-of-range values are safe.
 *
 * @param buffer Flat Color array of size width * height
 * @param y Row to draw on
 * @param x0 Start column (inclusive)
 * @param x1 End column (inclusive)
 * @param color Line color
 */
void HorizontalLine(img_buffer_t* buffer, int32_t y, int32_t x0, int32_t x1, const color_t color);

/**
 * Draws a vertical line down a single column of the framebuffer.
 * Coordinates are clamped to the buffer bounds, so out-of-range values are safe.
 *
 * @param buffer Flat Color array of size width * height
 * @param x Column to draw on
 * @param y0 Start row (inclusive)
 * @param y1 End row (inclusive)
 * @param color Line color
 */
void VerticalLine(img_buffer_t* buffer, int32_t x, int32_t y0, int32_t y1, const color_t color);

/**
 * Draw line with Bresenham's algorithm
 *
 * @param buffer Flat Color array of size width * height
 * @param x0 Line start x coordinate
 * @param y0 Line start y coordinate
 * @param x1 Line end x coordinate
 * @param y1 Line end y coordinate
 * @param color Line color
 */
void DrawLine(img_buffer_t* buffer, int32_t x0, int32_t y0, int32_t x1, int32_t y1, const color_t color);

/**
 * Draw an axis-aligned rectangle
 *
 * @param buffer Flat Color array of size width * height
 * @param x0 First corner x coordinate
 * @param y0 First corner y coordinate
 * @param x1 Second corner x coordinate
 * @param y1 Second corner y coordinate
 * @param outline Switch to draw shape outline
 * @param fill Switch to fill shape
 * @param outline_color Color of the outline
 * @param fill_color Color of the fill
 */
void DrawRectangle(img_buffer_t* buffer, int32_t x0, int32_t y0, int32_t x1, int32_t y1, bool outline, bool fill, const color_t outline_color, const color_t fill_color);

/**
 * Draw a circle using Bresenham's circle algorithm
 *
 * @param buffer Flat Color array of size width * height
 * @param cx Center x coordinate
 * @param cy Center y coordinate
 * @param radius Radius of circle
 * @param outline Switch to draw outline
 * @param fill Switch to fill shape
 * @param outline_color Color of the outline
 * @param fill_color Color of the fill
 */
void DrawCircle(img_buffer_t* buffer, int32_t cx, int32_t cy, int32_t radius, bool outline, bool fill, const color_t outline_color, const color_t fill_color);

/**
 * Draw triangle outline with specified color
 *
 * @param buffer Flat Color array of size width * height
 * @param v0 Location of corner a
 * @param v1 Location of corner b
 * @param v2 Location of corner c
 * @param outline_color Color of the outline
 */
void DrawTriangleOutline(img_buffer_t* buffer, vec2_t v0, vec2_t v1, vec2_t v2, const color_t outline_color);

/**
 * Draw flat bottom triangle
 *
 * @param buffer Flat Color array of size width * height
 * @param v0 Location of corner a
 * @param v1 Location of corner b
 * @param v2 Location of corner c
 * @param fill_color Color used to fill the shape
 */
void FlatBottomTriangle(img_buffer_t* buffer, vec2_t v0, vec2_t v1, vec2_t v2, const color_t fill_color);

/**
 * Draw flat top triangle
 *
 * @param buffer Flat Color array of size width * height
 * @param v0 Location of corner a
 * @param v1 Location of corner b
 * @param v2 Location of corner c
 * @param fill_color Color used to fill the shape
 */
void FlatTopTriangle(img_buffer_t* buffer, vec2_t v0, vec2_t v1, vec2_t v2, const color_t fill_color);

/**
 * Draw flat top triangle
 *
 * @param buffer Flat Color array of size width * height
 * @param v0 Location of corner a
 * @param v1 Location of corner b
 * @param v2 Location of corner c
 * @param fill_color Color used to fill the shape
 */
void DrawTriangle(img_buffer_t* buffer, vec2_t v0, vec2_t v1, vec2_t v2, const color_t fill_color);

#endif // MINI_RASTERIZER_RENDERER_H
