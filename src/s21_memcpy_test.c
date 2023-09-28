#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_memcpy_usual1) {
  char str1[5] = "abcd\0";
  char str2[5] = "gggg\0";
  char str3[5] = "gggg\0";
  s21_memcpy(str2, str1, 4);
  memcpy(str3, str1, 4);
  ck_assert_pstr_eq(str2, str3);
}
END_TEST

START_TEST(test_s21_string_memcpy_usual4) {
  char str1[5] = "abcd";
  char str2[5] = "gggg";
  char str3[5] = "gggg";
  s21_memcpy(str2, str1, 4);
  memcpy(str3, str1, 4);
  ck_assert_pstr_eq(str2, str3);
}
END_TEST

START_TEST(test_s21_string_memcpy_usual2) {
  char str1[6] = "abcd1\0";
  char str2[6] = "gggg1\0";
  char str3[6] = "gggg1\0";
  s21_memcpy(str2, str1, 4);
  memcpy(str3, str1, 4);
  ck_assert_pstr_eq(str2, str3);
}
END_TEST

START_TEST(test_s21_string_memcpy_usual3) {
  char str1[6] = "abcd1\0";
  char str2[6] = "gggg1\0";
  char str3[6] = "gggg2\0";
  s21_memcpy(str2, str1, 4);
  memcpy(str3, str1, 4);
  ck_assert_pstr_ne(str2, str3);
}
END_TEST

START_TEST(test_s21_string_memcpy_unusual1) {
  // char str1[14] = "abcdefgh";
  // char str2[14] = "abcdefgh";
  // s21_memcpy(str1 + 5, str1, 8);
  // memcpy(str2 + 5, str2, 8);
  // ck_assert_pstr_ne(str1, str2);
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_memcpy_usual, *tc_memcpy_unusual;

  s = suite_create("memcpy");

  tc_memcpy_usual = tcase_create("memcpy_usual");
  tcase_add_test(tc_memcpy_usual, test_s21_string_memcpy_usual1);
  tcase_add_test(tc_memcpy_usual, test_s21_string_memcpy_usual2);
  tcase_add_test(tc_memcpy_usual, test_s21_string_memcpy_usual3);
  tcase_add_test(tc_memcpy_usual, test_s21_string_memcpy_usual4);
  suite_add_tcase(s, tc_memcpy_usual);

  tc_memcpy_unusual = tcase_create("memcpy_unusual");
  tcase_add_test(tc_memcpy_unusual, test_s21_string_memcpy_unusual1);
  suite_add_tcase(s, tc_memcpy_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_pow_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
