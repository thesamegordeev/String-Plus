#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strcat_normal) {
  char str1[25] = "Hello";
  char str2[25] = "world!";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_pstr_eq(strcat(str2, str1), s21_strcat(str2, str1));
}
END_TEST

START_TEST(test_s21_string_strcat_broke) {
  char str1[25] = "Hello";
  char str2[25] = "wo\0rld!";
  char str3[5] = "\0";
  char str4[5] = "\0";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_pstr_eq(strcat(str2, str1), s21_strcat(str2, str1));
  ck_assert_pstr_eq(strcat(str3, str4), s21_strcat(str3, str4));
}
END_TEST

Suite *s21_string_strcat_suite() {
  Suite *s;
  TCase *tc_strcat_normal, *tc_strcat_broke;

  s = suite_create("strcat");

  tc_strcat_normal = tcase_create("strcat_normal");
  tcase_add_test(tc_strcat_normal, test_s21_string_strcat_normal);
  suite_add_tcase(s, tc_strcat_normal);

  tc_strcat_broke = tcase_create("strcat_broke");
  tcase_add_test(tc_strcat_broke, test_s21_string_strcat_broke);
  suite_add_tcase(s, tc_strcat_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_strcat_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
