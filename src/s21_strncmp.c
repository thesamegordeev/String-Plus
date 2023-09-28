#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int ret = 0, i = 0;
  s21_size_t counter = 0;
  while ((str1[i] != '\0' || str2[i] != '\0') && counter < n) {
    if (str1[i] != str2[i]) {
      ret = str1[i] - str2[i];
      break;
    }
    i++, counter++;
  }
  return ret;
}