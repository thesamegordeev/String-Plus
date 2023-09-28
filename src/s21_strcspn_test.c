#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strcspn_normal) {
  char str1[30] = "wHello world! Hello School 21!";
  char str2[30] = "Ok, I oul like to...";
  char str3[30] = "\0";
  char example[10] = "!";
  ck_assert_int_eq(strcspn(str1, example), s21_strcspn(str1, example));
  ck_assert_int_eq(strcspn(str2, example), s21_strcspn(str2, example));
  ck_assert_int_eq(strcspn(str3, example), s21_strcspn(str3, example));
}
END_TEST

START_TEST(test_s21_string_strcspn_broke) {
  char str1[30] = "01";
  char str2[30] = "\0";
  char example[10] = "1";
  ck_assert_int_eq(strcspn(str1, example), s21_strcspn(str1, example));
  ck_assert_int_eq(strcspn(str2, example), s21_strcspn(str2, example));
}
END_TEST

Suite *s21_string_strcspn_suite() {
  Suite *s;
  TCase *tc_strcspn_normal, *tc_strcspn_broke;

  s = suite_create("strcspn");

  tc_strcspn_normal = tcase_create("strcspn_normal");
  tcase_add_test(tc_strcspn_normal, test_s21_string_strcspn_normal);
  suite_add_tcase(s, tc_strcspn_normal);

  tc_strcspn_broke = tcase_create("strcspn_broke");
  tcase_add_test(tc_strcspn_broke, test_s21_string_strcspn_broke);
  suite_add_tcase(s, tc_strcspn_broke);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_strcspn_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
