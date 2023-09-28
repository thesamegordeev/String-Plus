#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *cur_char = s21_NULL;
  if (*str != '\0' && c != '\0') {
    while (*str != '\0') {
      if (*str == c) {
        cur_char = (char *)str;
      }
      str++;
    }
  } else if (c == '\0') {
    cur_char = (char *)(str + s21_strlen(str));
  }
  return (char *)cur_char;
}