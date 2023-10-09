#include "Arduino.h"
#include "Bitmap.h"

uint16_t* Bitmap::alloc_half_size() {
  log_d("Heap avail %lu, required %u Kb", esp_get_free_heap_size() / 1024, width * height / 2 * sizeof(uint16_t) / 1024);
  uint16_t *pixels = (uint16_t*) calloc(width * height / 2, sizeof(uint16_t));
  if (pixels == NULL) {
    log_e("malloc failed");
  }
  return pixels;
}

Bitmap::Bitmap(uint16_t a_width, uint16_t a_height) : width(a_width), height(a_height)
{
  // pixels1 = alloc_half_size();
  // pixels2 = alloc_half_size();
  rows = (uint16_t**) calloc(height, sizeof(uint16_t*));
  for (int i = 0; i < height / 2; i++)
  {
    if (pixels1) {
      rows[i] = pixels1 + width * i;
    }
    if (pixels2) {
      rows[i + height / 2] = pixels2 + width * i;
    }
  }
}

void Bitmap::scroll_left()
{
  for (int y = 0; y < height - 1; y++)
  {
    if (rows[y]) {
      memmove(rows[y], rows[y] + 1, this->width * sizeof(uint16_t) - 1);
    }
  }
}