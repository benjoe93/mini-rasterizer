# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Role

This is a learning project. Claude's role is research and explanation only — do not write, edit, or generate code. Help the user think through decisions and understand concepts; the user writes all the code themselves.

## Build

Uses CMake presets (`debug` / `release`) that place build artifacts in `intermediate/cmake/<preset>/` and the final binary in `bin/`.

```powershell
# Configure (first time or after CMakeLists.txt changes)
cmake --preset debug

# Build
cmake --build --preset debug

# Run (Windows, multi-config generator e.g. Visual Studio)
.\bin\Debug\mini_rasterizer.exe
```

### Linux

On Linux, CMake defaults to the Unix Makefiles generator, which is single-config — there's no `Debug`/`Release` subdirectory under `bin/`; the binary always lands at `bin/mini_rasterizer` regardless of which preset built it (the *previous* build's binary is simply overwritten if you switch presets).

```bash
# Debug build + run
cmake --preset debug
cmake --build --preset debug
./bin/mini_rasterizer

# Release build + run
cmake --preset release
cmake --build --preset release
./bin/mini_rasterizer
```

Each preset gets its own build tree (`intermediate/cmake/debug/` vs `intermediate/cmake/release/`) and its own vendored minifb checkout (`external/debug/` vs `external/release/`), so switching presets never requires a clean — just re-run `cmake --preset <name>` if it hasn't been configured yet, then `cmake --build --preset <name>`.

The minifb dependency is fetched automatically via `FetchContent` on first configure into `external/<preset>/`.

## Architecture

This is a C99 software rasterizer learning project. Progress and next steps are tracked in `LEARNING_PLAN.md`. minifb is fully wired into `main` and drives the primary render loop; PPM export still exists but now runs on demand (press `P`) rather than unconditionally at startup.

**Core types** (`include/types.h`): `color_t` (r/g/b `uint8_t`), `img_details_t` (path, max_val), `img_buffer_t` (pixels, width, height), and `screenshot_ctx_t` (bundles a buffer + img_details for the keyboard callback).

**Module status**:
- `include/renderer.h` / `src/renderer.c` — implemented: `ClearScreen`, `PutPixel`, `DrawHorizontalLine`, `DrawVerticalLine`, `DrawLine` (Bresenham), `DrawRectangle`, `DrawCircle` (midpoint algorithm). Triangle rasterization (Stage 4) not yet started.
- `include/math_utils.h` / `src/math_utils.c` — implemented: `Lerpf`, `Remapf`, and `Vector2` ops (add/sub/multiply/scale/lerp/dot). `Vector3`/`Vector4` structs are declared but have no ops yet (Stage 5).
- `include/mesh.h` — still an empty stub (Cube/Pyramid geometry, not started).

**Current rendering flow** (`src/main.c`):
1. Open a resizable minifb window and allocate a flat `color_t*` framebuffer (`WIDTH * HEIGHT`) plus a `uint32_t*` scratch buffer for minifb.
2. Each frame: `ClearScreen`, draw primitives into the `color_t*` buffer, then `ConvertToUint32()` into the `uint32_t*` (0xRRGGBB packed) buffer and hand it to `mfb_update_ex` / `mfb_wait_sync`.
3. A keyboard callback (`screenshot_callback`) calls `WriteToPpm()` on `P` keypress to serialize the current `color_t*` buffer to PPM P3 format.

**Output**: PPM files go to `saved/out.ppm` at the repo root — the path is baked in via the `OUTPUT_DIR` compile definition set in `CMakeLists.txt` (`${CMAKE_SOURCE_DIR}/saved`), not a relative path from the binary.
