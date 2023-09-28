#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *cp_str = s21_NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    cp_str = malloc((length + 1) * sizeof(char));
    s21_strcpy(cp_str, str);
    for (s21_size_t i = 0; i < length; i++) {
      if (cp_str[i] >= 'a' && cp_str[i] <= 'z') {
        cp_str[i] -= 32;
      }
      cp_str[length] = '\0';
    }
  }
  return cp_str;
}
