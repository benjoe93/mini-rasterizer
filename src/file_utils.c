// File handling utilities
#include "file_utils.h"
#include <stdio.h>

void WriteToPpm(const img_buffer_t* buffer, const img_details_t* image) {
  // open file
  FILE *file = fopen(image->path, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file!\n");
    return;
  }

  // write file
  fputs("P3\n", file); // ppm header
  fprintf(file, "%u %u\n", buffer->width, buffer->height);
  fprintf(file, "%u\n", (unsigned int)image->max_val);

  // pixels
  for (size_t i = 0; i < (size_t)buffer->height * buffer->width; i++) {
    fprintf(file, "%u %u %u\n", buffer->pixels[i].r, buffer->pixels[i].g, buffer->pixels[i].b);
  }

  // close file
  fclose(file);
}

void ConvertToUint32(const img_buffer_t* src, uint32_t* dst) {
  for (size_t i = 0; i < src->height * src->width; i++) {
    dst[i]  = ((uint32_t)src->pixels[i].r << 16)
            | ((uint32_t)src->pixels[i].g << 8)
            | ((uint32_t)src->pixels[i].b);
  }
}

