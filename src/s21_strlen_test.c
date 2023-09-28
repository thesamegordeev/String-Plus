#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strlen_normal) {
  char str1[30] = "Hello world! Hello School 21!";
  char str2[30] = "Ok, I would like to...";
  char str3[30] = "Hey!";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
}
END_TEST

START_TEST(test_s21_string_strlen_broke) {
  char str1[30] = "";
  char str2[30] = "\0";
  char str3[30] = "Oh s\0it... Here we go again";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
}
END_TEST

Suite *s21_string_strlen_suite() {
  Suite *s;
  TCase *tc_strlen_normal, *tc_strlen_broke;

  s = suite_create("strlen");

  tc_strlen_normal = tcase_create("strlen_normal");
  tcase_add_test(tc_strlen_normal, test_s21_string_strlen_normal);
  suite_add_tcase(s, tc_strlen_normal);

  tc_strlen_broke = tcase_create("strlen_broke");
  tcase_add_test(tc_strlen_broke, test_s21_string_strlen_broke);
  suite_add_tcase(s, tc_strlen_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_strlen_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
