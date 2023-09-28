// checkmk clean_mode=1 strrchr.check > s21_strrchr_test.c

#include <check.h>
#include <string.h>

#include "s21_string.h"

char *s21_strrchr(const char *str, int c);

START_TEST(test_s21_string_strrchr_usual1) {
  char *str = "abobus";
  ck_assert_pstr_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}
END_TEST

START_TEST(test_s21_string_strrchr_usual2) {
  char *str =
      "ffffffffffffffffffffffffffffffffffffffffffffssssssssssssssssssss";
  ck_assert_pstr_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}
END_TEST

START_TEST(empty_str) {
  char *str = "";
  ck_assert_pstr_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}
END_TEST

START_TEST(test_s21_string_strrchr_usual3) {
  char *str = "aaabib";
  ck_assert_pstr_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}
END_TEST

START_TEST(terminate_null) {
  char *str = "abibus";
  ck_assert_pstr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

Suite *s21_strrchr_suite() {
  Suite *s;
  TCase *tc_strrchr_normal = tcase_create("strrchr_normal");

  s = suite_create("strrchr");
  tcase_add_test(tc_strrchr_normal, test_s21_string_strrchr_usual1);
  tcase_add_test(tc_strrchr_normal, test_s21_string_strrchr_usual2);
  tcase_add_test(tc_strrchr_normal, test_s21_string_strrchr_usual3);
  tcase_add_test(tc_strrchr_normal, empty_str);
  tcase_add_test(tc_strrchr_normal, terminate_null);
  suite_add_tcase(s, tc_strrchr_normal);
  return s;
}

int main(void) {
  Suite *s;
  int failed = 0;
  SRunner *runner;
  s = s21_strrchr_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : 1;
}

// gcc -c -Wall -pthread -fprofile-arcs -ftest-coverage s21_test_strrchr.c
// gcc s21_test_strrchr.o -lcheck_pic -pthread -lrt -lm -lsubunit -lgcov
// -coverage