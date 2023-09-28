#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *ans = s21_NULL;
  while (n--) {
    if (*(char *)str == c) {
      ans = (void *)str;
      break;
    }
    str++;
  }
  return ans;
}
