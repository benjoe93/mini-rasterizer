# Rasterizer Learning Plan

## Stage 1: Output & Primitives
- [x] Pixel buffer + PPM file output
- [x] Fill screen with solid color
- [x] Draw horizontal line
- [x] Draw vertical line
- [ ] Draw arbitrary line (Bresenham's line algorithm)
- [ ] Draw rectangle (filled and outline)
- [ ] Draw circle (midpoint circle algorithm)

## Stage 2: Windowed Display
- [ ] Open a window with minifb
- [ ] Render pixel buffer to window each frame
- [ ] Handle window close / ESC key
- [ ] Basic frame loop (update → render)

## Stage 3: 2D Math Foundations
- [ ] Vec2 struct (float x, y) and basic ops (add, sub, scale, dot)
- [ ] Lerp (linear interpolation) between two values
- [ ] Map/remap a value between ranges

## Stage 4: Triangle Rasterization
- [ ] Draw triangle outline (3 lines)
- [ ] Fill flat-bottom triangle
- [ ] Fill flat-top triangle
- [ ] Fill arbitrary triangle (split into flat-bottom + flat-top)
- [ ] Barycentric coordinates — compute for a point inside a triangle

## Stage 5: 3D Math Foundations
- [ ] Vec3 struct and ops (add, sub, scale, dot, cross, normalize, length)
- [ ] 4x4 matrix struct and ops (multiply matrix × matrix, matrix × vec4)
- [ ] Projection matrix (perspective divide)
- [ ] View/camera matrix (look-at)

## Stage 6: 3D Pipeline
- [ ] Load a hardcoded triangle in 3D space
- [ ] Transform vertices (model → world → view → clip)
- [ ] Perspective projection to screen space
- [ ] Render projected triangle with flat shading

## Stage 7: Depth & Correctness
- [ ] Z-buffer (depth buffer) — allocate, clear, test per pixel
- [ ] Perspective-correct barycentric interpolation
- [ ] Back-face culling

## Stage 8: OBJ Loading
- [ ] Parse a minimal .obj file (v, f records only)
- [ ] Render a loaded mesh with flat shading
- [ ] Parse vertex normals (vn)

## Stage 9: Shading
- [ ] Flat shading (one normal per face, one color per triangle)
- [ ] Gouraud shading (interpolate per-vertex normals across triangle)
- [ ] Directional light (diffuse: N · L)
- [ ] Ambient + diffuse lighting model

## Stage 10: Texturing
- [ ] UV coordinates — parse from .obj (vt records)
- [ ] Load a PPM texture
- [ ] Nearest-neighbor texture sampling
- [ ] Apply texture to a triangle (with perspective-correct UVs)
- [ ] Bilinear texture filtering
