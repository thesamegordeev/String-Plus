#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *symb = s21_NULL;
  while (*str != c && *str) str++;
  if (*str || (*str == '\0' && c == '\0')) {
    symb = (char *)str;
  }
  return symb;
}