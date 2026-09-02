#ifndef MINI_RASTERIZER_SCENES_H
#define MINI_RASTERIZER_SCENES_H

#include "renderer.h"

static void scene_01_shapes(img_buffer_t* buffer) {
    // draw line middle of the image
    color_t line_color = {255, 0, 0};
    HorizontalLine(buffer, 300, 0, (int32_t)buffer->width, line_color);

    VerticalLine(buffer, 400, 0, (int32_t)buffer->height, line_color);

    line_color = (color_t){255, 255, 0};
    DrawLine(buffer, 790, 10, 10, 590, line_color);

    // Draw astrix
    line_color = (color_t){0, 255, 0};
    DrawLine(buffer,  75, 150, 325, 150, line_color);
    DrawLine(buffer,  85, 102, 315, 198, line_color);
    DrawLine(buffer, 112,  62, 288, 238, line_color);
    DrawLine(buffer, 152,  35, 248, 265, line_color);
    DrawLine(buffer, 200,  25, 200, 275, line_color);
    DrawLine(buffer, 248,  35, 152, 265, line_color);
    DrawLine(buffer, 288,  62, 112, 238, line_color);
    DrawLine(buffer, 315, 102,  85, 198, line_color);

    // Draw axis-aligned rectangle
    line_color = (color_t){0, 255, 125};
    color_t fill_color = {0, 125, 255};
    DrawRectangle(buffer, 700, 550, 500, 350, true, true, line_color, fill_color);

    // Draw circle
    DrawCircle(buffer, 200, 450, 100, true, true, line_color, fill_color);
}

static void scene_02_triangles(img_buffer_t* buffer) {
    // flat bottom triangle
    vec2_t v0 = {.x = 250.f, .y = 300.f};
    vec2_t v1 = {.x = 150.f, .y =  80.f};
    vec2_t v2 = {.x =  50.f, .y = 300.f};
    color_t color = {.r = 255, .g = 0, .b = 0};
    color_t outline_color = {.r = 255, .g = 255, .b = 255};

    DrawTriangle(buffer, v0, v1, v2, color);
    DrawTriangleOutline(buffer, v0, v1, v2, outline_color);

    // flat top triangle
    v0 = (vec2_t){.x = 650.f, .y = 500.f};
    v1 = (vec2_t){.x = 750.f, .y = 150.f};
    v2 = (vec2_t){.x = 550.f, .y = 150.f};
    color = (color_t){.r = 0, .g = 255, .b = 0};

    DrawTriangle(buffer, v0, v1, v2, color);
    DrawTriangleOutline(buffer, v0, v1, v2, outline_color);

    // triangle
    v0 = (vec2_t){.x = 480.f, .y = 350.f};
    v1 = (vec2_t){.x = 300.f, .y = 550.f};
    v2 = (vec2_t){.x = 340.f, .y =  50.f};
    color = (color_t){.r = 0, .g = 0, .b = 255};

    DrawTriangle(buffer, v0, v1, v2, color);
    DrawTriangleOutline(buffer, v0, v1, v2, outline_color);
}

#endif //MINI_RASTERIZER_SCENES_H
