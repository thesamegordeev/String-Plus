#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *st_res = s21_NULL;
  if (src != s21_NULL) {
    st_res = calloc((s21_strlen(src) + 2), sizeof(char));
    char *res = st_res;
    int flag = 1;
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_trim;
    if (trim_chars != s21_NULL) {
      len_trim = s21_strlen(trim_chars);
    } else {
      len_trim = 0;
    }
    for (s21_size_t i = 0; i < len_src; i++) {
      for (s21_size_t j = 0; j < len_trim && flag; j++) {
        if (src[i] == trim_chars[j]) {
          flag = 0;
        }
      }
      if (flag == 1) {
        for (; i < len_src; i++) {
          *res++ = src[i];
        }
      } else {
        flag = 1;
      }
    }
    flag = 1;
    if (!*st_res) {
      return st_res;
    }
    for (s21_size_t i = len_src - 1; (int)i >= 0; i--) {
      for (s21_size_t j = 0; j < len_trim && flag; j++) {
        if (src[i] == trim_chars[j]) {
          flag = 0;
          *--res = '\0';
        }
      }
      if (flag == 1) {
        for (; (int)i >= 0; i--)
          ;
      } else {
        flag = 1;
      }
    }
  }
  return st_res;
}