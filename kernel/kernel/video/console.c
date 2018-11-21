#include <kernel/video/console.h>
#include <kernel/util/string.h>

static uint8_t* vMemory = (uint8_t*) VIDEO_MEMORY;
static uint8_t color = DEFAULT_COLOR;
uint32_t offset = 0;

void print(char c) {
  if (c == '\n') {
    if (offset % (WIDTH * 2) == 0) {
      print(' ');
    }
    while (offset % (WIDTH * 2) != 0) {
      print(' ');
    }
  }
  else {
    vMemory[offset++] = c;
    vMemory[offset++] = color;
  }
}

void putChar(uint16_t x, uint16_t y, char c, uint8_t color) {
  vMemory[y * (WIDTH * 2) + x * 2] = c;
  vMemory[y * (WIDTH * 2) + x * 2 + 1] = color;
}
void putString(uint16_t x, uint16_t y, const char* c, uint8_t color) {
  while (*c) {
    putChar(x++, y, *c, color);
    if (x > WIDTH) {
      x = 0;
      y++;
    }
    if (y > HEIGHT) {
      y = 0;
    }
    ++c;
  }
}
void setColor(uint8_t nColor) {
  color = nColor;
}
void clearConsole() {
  for (uint32_t i = 0; i < 25; i++) {
    print('\n');
  }
  offset = 0;
}
void scrollUp() {
  clearConsole();
}

void printk(char* str) {
  for (int i = 0; i < length(str); i++) {
    print(str[i]);
  }
}
