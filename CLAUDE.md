# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Role

This is a learning project. Claude's role is research and explanation only — do not write, edit, or generate code. Help the user think through decisions and understand concepts; the user writes all the code themselves.

## Build

Uses CMake with a preset that places build artifacts in `intermediate/cmake/` and the final binary in `bin/`.

```powershell
# Configure (first time or after CMakeLists.txt changes)
cmake --preset default

# Build
cmake --build --preset default

# Run (Windows)
.\bin\Debug\mini_rasterizer.exe

# Run (Linux/WSL)
./bin/Debug/mini_rasterizer
```

The minifb dependency is fetched automatically via `FetchContent` on first configure into `external/`.

## Architecture

This is a C11 software rasterizer learning project. Progress and next steps are tracked in `LEARNING_PLAN.md`. The current output path is PPM file rendering (`saved/out.ppm`); a live window path via minifb exists in `src/minifb_setup.c` but is not yet wired into `main`.

**Core types** (`include/types.h`): `Color` (R/G/B ints) and `ImgDetails` (path, width, height, max_val) are the primitive data types used throughout.

**Planned module structure** (headers exist as stubs):
- `include/renderer.h` — rasterization pipeline logic
- `include/math_utils.h` — vectors, matrices, transformations
- `include/mesh.h` — geometry definitions (Cube, Pyramid)

**Current rendering flow** (`src/main.c`):
1. Allocate a flat `Color*` framebuffer (`WIDTH * HEIGHT`)
2. Fill with clear color, draw primitives by writing into `x + y * WIDTH` indexed slots
3. Call `WriteToPpm()` to serialize to PPM P3 format

**minifb integration** (`src/minifb_setup.c`): `window_setup()` opens a resizable window and drives a render loop using `mfb_update_ex` / `mfb_wait_sync`. The framebuffer here is `uint32_t*` (0xRRGGBB packed), distinct from the `Color*` struct used in the PPM path.

**Output**: PPM files go to `../../saved/out.ppm` relative to the binary (i.e., `saved/` at the repo root).
