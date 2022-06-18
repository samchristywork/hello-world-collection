#include <png.h>
#include <stdlib.h>

int main() {
  png_image image = {0};

  image.width = 100;
  image.height = 100;
  image.format = PNG_FORMAT_RGBA;
  image.version = PNG_IMAGE_VERSION;

  png_bytep buffer = malloc(PNG_IMAGE_SIZE(image));
  for (int x = 0; x < image.width; x++) {
    for (int y = 0; y < image.height; y++) {
      buffer[(x + y * image.width) * 4 + 0] = (float)x / image.width * 255;
      buffer[(x + y * image.width) * 4 + 1] = (float)y / image.width * 255;
      buffer[(x + y * image.width) * 4 + 2] = 0;
      buffer[(x + y * image.width) * 4 + 3] = 255;
    }
  }
  if (!png_image_write_to_file(&image, "build/out.png", 0, buffer, 0, NULL)) {
    fprintf(stderr, "libpng: Failed to write to file.\n");
    exit(EXIT_FAILURE);
  }
}
