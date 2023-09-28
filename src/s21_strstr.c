#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  char *toSearch = (char *)haystack;
  char *toFind = (char *)needle;
  int i = 0;
  char *pointer =
      (toFind[0] == '\0' && toSearch[0] != '\0') ? toSearch : s21_NULL;
  while (toSearch[i] != '\0' && pointer == s21_NULL) {
    if (toSearch[i] == toFind[0]) {
      pointer = &toSearch[i];
      int j = 0, k = i;
      while (toFind[j] != '\0' && toSearch[k] != '\0') {
        if (toSearch[k] != toFind[j]) {
          pointer = s21_NULL;
          break;
        }
        k++;
        j++;
      }
      if (toFind[j] != '\0') pointer = s21_NULL;
    }
    i++;
  }
  return pointer;
}