// File handling utilities
#include "file_utils.h"
#include <stdio.h>

void WriteToPpm(const img_buffer_t *buffer, const img_details_t *image) {
  // open file
  FILE *file = fopen(image->path, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file!\n");
    return;
  }

  // write file
  fputs("P3\n", file); // ppm header
  fprintf(file, "%u %u\n", buffer->width, buffer->height);
  fprintf(file, "%u\n", image->max_val);

  // pixels
  for (unsigned int i = 0; i < buffer->height * buffer->width; i++) {
    fprintf(file, "%u %u %u\n", buffer->pixels[i].R, buffer->pixels[i].G,
            buffer->pixels[i].B);
  }

  // close file
  fclose(file);
}
