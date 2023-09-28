#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *st_res = s21_NULL;

  if (src && s21_strlen(src) >= start_index &&
      start_index == abs((int)start_index)) {
    s21_size_t len_str;
    if (str != s21_NULL) {
      len_str = s21_strlen(str);
    } else {
      return st_res;
    }
    st_res = calloc((s21_strlen(src) + len_str + 4), sizeof(char));
    char *res = st_res;
    s21_size_t i = 0;
    while (i < N && (*str || *src)) {
      if (i != start_index) {
        *res++ = *src++;
        i++;
      } else {
        while (*str) {
          *res++ = *str++;
          i++;
        }
        i++;
      }
    }
  }
  return st_res;
}