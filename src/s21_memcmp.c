#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *cstr1 = (char *)str1;
  char *cstr2 = (char *)str2;
  int ret = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (cstr1[i] != cstr2[i]) {
      if (cstr1[i] < cstr2[i]) ret = -1;
      if (cstr1[i] > cstr2[i]) ret = 1;
      break;
    }
  }
  return ret;
}
