#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strcmp_normal) {
  char str1[10] = "Hello";
  char str2[10] = "Hello";
  char str3[10] = "Hello!";
  char str4[10] = "hello!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strcmp(str1, str3), s21_strcmp(str1, str3));
  ck_assert_int_eq(strcmp(str1, str4), s21_strcmp(str1, str4));
}
END_TEST

START_TEST(test_s21_string_strcmp_broke) {
  char str1[2] = "";
  char str2[2] = "Q";
  char str3[2] = "\0";
  char str4[10] = "Hel\0lo!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strcmp(str1, str3), s21_strcmp(str1, str3));
  ck_assert_int_eq(strcmp(str3, str2), s21_strcmp(str3, str2));
  ck_assert_int_eq(strcmp(str4, str3), s21_strcmp(str4, str3));
}
END_TEST

Suite *s21_string_strcmp_suite() {
  Suite *s;
  TCase *tc_strcmp_normal, *tc_strcmp_broke;

  s = suite_create("strcmp");

  tc_strcmp_normal = tcase_create("strcmp_normal");
  tcase_add_test(tc_strcmp_normal, test_s21_string_strcmp_normal);
  suite_add_tcase(s, tc_strcmp_normal);

  tc_strcmp_broke = tcase_create("strcmp_broke");
  tcase_add_test(tc_strcmp_broke, test_s21_string_strcmp_broke);
  suite_add_tcase(s, tc_strcmp_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_strcmp_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
