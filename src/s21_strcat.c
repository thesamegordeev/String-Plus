#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *end_dest = s21_strlen(dest) + dest;
  while (*src != '\0') *end_dest++ = *src++;
  *end_dest = '\0';
  return dest;
}
