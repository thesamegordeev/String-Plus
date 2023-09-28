#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t i = 0;
  s21_size_t j = 0;
  int breakflag = 0;
  char *ret = s21_NULL;
  while (str1[i] != '\0' && !breakflag) {
    j = 0;
    while (str2[j] != '\0' && !breakflag) {
      if (str1[i] == str2[j]) {
        ret = (char *)&str1[i];
        breakflag = 1;
      }
      j++;
    }
    i++;
  }
  return ret;
}
