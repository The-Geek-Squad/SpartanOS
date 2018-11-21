#include <kernel/util/string.h>

int length(const char* str) {
  int size = 0;
  while (*str++) {
    ++size;
  }
  return size;
}
