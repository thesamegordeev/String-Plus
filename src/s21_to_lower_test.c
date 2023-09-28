#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_to_lower) {
  char str1[40] = "HELLO WORLD! HELLO SCHOOL 21!\0";
  char res1[50] = "hello world! hello school 21!\0";
  char str5[40] = "HEllO WoRLD! HeLLO SChOOL 21!\0";
  char str2[100] = "A B C D E F G H I K L M N O P Q R S T V X Y Z\0";
  char res2[100] = "a b c d e f g h i k l m n o p q r s t v x y z\0";

  char *str3 = s21_NULL;
  char *str4 = NULL;
  char *test1 = s21_to_lower(str1);
  char *test2 = s21_to_lower(str2);
  char *test3 = s21_to_lower(str3);
  char *test4 = s21_to_lower(str4);
  char *test5 = s21_to_lower(str5);
  char *test6 = s21_to_lower("\0");
  ck_assert_str_eq(test6, "");
  ck_assert_str_eq(test5, res1);
  ck_assert_str_eq(test1, res1);
  ck_assert_str_eq(test2, res2);
  ck_assert_ptr_null(test3);
  ck_assert_ptr_null(test4);
  free(test1);
  free(test2);
  free(test3);
  free(test4);
  free(test5);
  free(test6);
}
END_TEST

Suite *s21_string_to_lower_suite() {
  Suite *s;
  TCase *tc_to_lower;

  s = suite_create("to_lower");

  tc_to_lower = tcase_create("to_lower");
  tcase_add_test(tc_to_lower, test_s21_string_to_lower);
  suite_add_tcase(s, tc_to_lower);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_string_to_lower_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
