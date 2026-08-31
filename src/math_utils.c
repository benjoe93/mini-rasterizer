#include "math_utils.h"

float learp_f(float a, float b, float t) { return a + (b - a) * t; }

float remap_f(float value, float in_min, float in_max, float out_min,
             float out_max) {
  return out_min + (out_max - out_min) * ((value - in_min) / (in_max - in_min));
}

vec2_t vec2_add(vec2_t a, vec2_t b) {
  return (vec2_t){
      .x = a.x + b.x,
      .y = a.y + b.y,
  };
}

vec2_t vec2_sub(vec2_t a, vec2_t b) {
  return (vec2_t){
      .x = a.x - b.x,
      .y = a.y - b.y,
  };
}

vec2_t vec2_mult(vec2_t a, vec2_t b) {
  return (vec2_t){
      .x = a.x * b.x,
      .y = a.y * b.y,
  };
}

vec2_t vec2_scale(vec2_t vector, float scaler) {
  return (vec2_t){
      .x = vector.x * scaler,
      .y = vector.y * scaler,
  };
}

vec2_t vec2_lerp(vec2_t a, vec2_t b, float t) {
  return (vec2_t){
      .x = learp_f(a.x, b.x, t),
      .y = learp_f(a.y, b.y, t),
  };
}

float vec2_dot(vec2_t a, vec2_t b) { return (a.x * b.x) + (a.y * b.y); }

void vec2_swap(vec2_t* a, vec2_t* b) {
    vec2_t tmp = *a;
    *a = *b;
    *b = tmp;
}
