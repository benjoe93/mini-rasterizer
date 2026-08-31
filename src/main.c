#include <stdlib.h>

#include "MiniFB.h"
#include "MiniFB_enums.h"

#include "file_utils.h"
#include "renderer.h"
#include "types.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR_VALUE 255

#define OUT_PATH OUTPUT_DIR "/out.ppm"

void screenshot_callback(struct mfb_window *window, mfb_key key, mfb_key_mod mod, bool is_pressed);

int main(void) {
    // setup minifb window
    struct mfb_window* window = mfb_open_ex("Mini Rasterizer", WIDTH, HEIGHT, MFB_WF_RESIZABLE);
    if (window == NULL) { return 1; }

    mfb_update_state state;

    // setup ppm image
    img_details_t img = {OUT_PATH, MAX_COLOR_VALUE};

    // buffer setup
    color_t *pixels = malloc(WIDTH * HEIGHT * sizeof(color_t));
    if (!pixels) { return 2; }

    img_buffer_t buffer = {pixels, WIDTH, HEIGHT};
    uint32_t* mfb_buffer = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
    if (mfb_buffer == NULL) { return 1; }

    screenshot_ctx_t screenshot_ctx = {
        .buffer = &buffer,
        .img = &img
    };

    // register keypress callback & store userdata
    mfb_set_keyboard_callback(window, screenshot_callback);
    mfb_set_user_data(window, &screenshot_ctx);

    do {
        // clear screen
        ClearScreen(&buffer, (color_t) {26, 34, 56});

        // draw line middle of the image
        color_t line_color = {255, 0, 0};
        HorizontalLine(&buffer, 300, 0, buffer.width, line_color);

        VerticalLine(&buffer, 400, 0, buffer.height, line_color);

        line_color = (color_t){255, 255, 0};
        DrawLine(&buffer, 790, 10, 10, 590, line_color);

        // Draw astrix
        line_color = (color_t){0, 255, 0};
        DrawLine(&buffer,  75, 150, 325, 150, line_color);
        DrawLine(&buffer,  85, 102, 315, 198, line_color);
        DrawLine(&buffer, 112,  62, 288, 238, line_color);
        DrawLine(&buffer, 152,  35, 248, 265, line_color);
        DrawLine(&buffer, 200,  25, 200, 275, line_color);
        DrawLine(&buffer, 248,  35, 152, 265, line_color);
        DrawLine(&buffer, 288,  62, 112, 238, line_color);
        DrawLine(&buffer, 315, 102,  85, 198, line_color);

        // Draw axis-aligned rectangle
        line_color = (color_t){0, 255, 125};
        color_t fill_color = {0, 125, 255};
        DrawRectangle(&buffer, 700, 550, 500, 350, true, true, line_color, fill_color);

        // Draw circle
        DrawCircle(&buffer, 200, 450, 100, true, true, line_color, fill_color);


        ConvertToUint32(&buffer, mfb_buffer);

        state = mfb_update_ex(window, mfb_buffer, buffer.width, buffer.height);
        if (state != MFB_STATE_OK) {break;}
    } while (mfb_wait_sync(window));

    free(mfb_buffer);
    free(pixels);
    pixels = NULL;
    buffer.pixels = NULL;
    return 0;
}

void screenshot_callback(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool is_pressed) {
    (void)mod;
    screenshot_ctx_t* ctx = (screenshot_ctx_t*)mfb_get_user_data(window);

    // take screenshot
    if (key == MFB_KB_KEY_P && is_pressed) {
        WriteToPpm(ctx->buffer, ctx->img);
    }
}
