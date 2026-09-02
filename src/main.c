#include <stdlib.h>

#include "MiniFB.h"
#include "MiniFB_enums.h"

#include "file_utils.h"
#include "renderer.h"
#include "types.h"

#include "scenes.h"

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
        ClearScreen(&buffer, (color_t) {.r = 26, .g = 34, .b = 56});

        // scenes
        // scene_01_shapes(&buffer);
        scene_02_triangles(&buffer);

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
