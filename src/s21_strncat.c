#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *end_dest = s21_strlen(dest) + dest;
  while (*src != '\0' && n--) *end_dest++ = *src++;
  *end_dest = '\0';
  return dest;
}
