#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_to_upper) {
  char str1[40] = "HELLO WORLD! HELLO SCHOOL 21!\0";
  char res1[50] = "hello world! hello school 21!\0";
  char str5[40] = "\0HEllO WoRLD! HeLLO SChOOL 21!\0";
  char str2[100] = "\0";
  char res2[100] = "a b c d e f g h i k l m n o p q r s t v x y z\0";

  char *str3 = s21_NULL;
  char *str4 = NULL;
  char *test1 = s21_to_upper(str1);
  char *test2 = s21_to_upper(str2);
  char *test3 = s21_to_upper(str3);
  char *test4 = s21_to_upper(res1);
  char *test5 = s21_to_upper(str5);
  ck_assert_str_eq(test5, "\0");
  ck_assert_str_eq(test1, str1);
  ck_assert_str_eq(test2, "\0");
  ck_assert_ptr_null(test3);
  ck_assert_str_eq(test4, str1);
  free(test1);
  free(test2);
  free(test3);
  free(test4);
  free(test5);
}
END_TEST

Suite *s21_string_to_upper_suite() {
  Suite *s;
  TCase *tc_to_upper;

  s = suite_create("to_upper");

  tc_to_upper = tcase_create("to_upper");
  tcase_add_test(tc_to_upper, test_s21_string_to_upper);
  suite_add_tcase(s, tc_to_upper);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_to_upper_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
