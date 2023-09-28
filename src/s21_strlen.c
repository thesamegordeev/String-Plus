#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t strlen = 0;
  while (*str++) strlen++;
  return strlen;
}