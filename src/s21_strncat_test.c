#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strncat_normal) {
  char str1[25] = "Hello";
  char str2[25] = "world!";
  ck_assert_pstr_eq(strncat(str1, str2, 5), s21_strncat(str1, str2, 5));
  ck_assert_pstr_eq(strncat(str2, str1, 3), s21_strncat(str2, str1, 3));
}
END_TEST

START_TEST(test_s21_string_strncat_broke) {
  char str1[25] = "Hello";
  char str2[25] = "wo\0rld!";
  char str3[5] = "\0";
  char str4[5] = "\0";
  ck_assert_pstr_eq(strncat(str1, str2, 5), s21_strncat(str1, str2, 5));
  ck_assert_pstr_eq(strncat(str2, str1, 3), s21_strncat(str2, str1, 3));
  ck_assert_pstr_eq(strncat(str3, str4, 3), s21_strncat(str3, str4, 3));
}
END_TEST

Suite *s21_string_strncat_suite() {
  Suite *s;
  TCase *tc_strncat_normal, *tc_strncat_broke;

  s = suite_create("strncat");

  tc_strncat_normal = tcase_create("strncat_normal");
  tcase_add_test(tc_strncat_normal, test_s21_string_strncat_normal);
  suite_add_tcase(s, tc_strncat_normal);

  tc_strncat_broke = tcase_create("strncat_broke");
  tcase_add_test(tc_strncat_broke, test_s21_string_strncat_broke);
  suite_add_tcase(s, tc_strncat_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_strncat_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
