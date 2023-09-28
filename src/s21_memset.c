#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *buf = (char *)str;
  while (n--) {
    *buf++ = c;
  }
  return str;
}
