#ifndef MINI_RASTERIZER_MATH_UTILS_H
#define MINI_RASTERIZER_MATH_UTILS_H
// Vectors, matrices, transformations

typedef struct  {
    float x;
    float y;
} vec2_t;

typedef struct  {
    float x;
    float y;
    float z;
} vec3_t;

typedef struct  {
    float x;
    float y;
    float z;
    float w;
} vec4_t;

float learp_f(float a, float b, float t);
float remap_f(float value, float in_min, float in_max, float out_min, float out_max);

vec2_t vec2_add(vec2_t a, vec2_t b);
vec2_t vec2_sub(vec2_t a, vec2_t b);
vec2_t vec2_mult(vec2_t a, vec2_t b);
vec2_t vec2_scale(vec2_t vector, float scaler);
vec2_t vec2_lerp(vec2_t a, vec2_t b, float t);
float vec2_dot(vec2_t a, vec2_t b);
void vec2_swap(vec2_t* a, vec2_t* b);
#endif //MINI_RASTERIZER_MATH_UTILS_H
