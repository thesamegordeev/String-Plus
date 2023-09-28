#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *cdest = (char *)dest;
  char *csrc = (char *)src;
  char tmp[n];
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = csrc[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    cdest[i] = tmp[i];
  }
  return dest;
}
