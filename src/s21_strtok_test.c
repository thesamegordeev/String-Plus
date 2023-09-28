#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strtok_usual) {
  char str1[] = "dir1/di.r2/d.ir3/di.r4";
  char str2[] = "dir1/di.r2/d.ir3/di.r4";
  char delim1[] = "/.";
  char *p1 = strtok(str1, delim1);
  char *p2 = s21_strtok(str2, delim1);
  while (p1 != s21_NULL && p2 != s21_NULL) {
    p1 = strtok(s21_NULL, delim1);
    p2 = s21_strtok(s21_NULL, delim1);
    ck_assert_pstr_eq(p1, p2);
  }

  char str3[] = "Lorem ipsum dolor sit amet";
  char str4[] = "Lorem ipsum dolor sit amet";
  char delim[] = " ";
  char *p3 = strtok(str3, delim);
  char *p4 = s21_strtok(str4, delim);
  while (p3 != s21_NULL && p4 != s21_NULL) {
    p3 = strtok(s21_NULL, delim);
    p4 = s21_strtok(s21_NULL, delim);
    ck_assert_pstr_eq(p1, p2);
  }
}
END_TEST

START_TEST(test_s21_string_strtok_unusual) {
  char str1[] = "dir1/di.r2/d.ir3/di.r4";
  char delim[] = "&";
  ck_assert_ptr_null(s21_strtok(s21_NULL, delim));
  ck_assert_ptr_null(s21_strtok(s21_NULL, s21_NULL));
  ck_assert_ptr_eq(s21_strtok(str1, ""), strtok(str1, ""));
}
END_TEST

Suite *s21_strtok_suite() {
  Suite *s;
  TCase *tc_strtok_usual, *tc_strtok_unusual;

  s = suite_create("strtok");

  tc_strtok_usual = tcase_create("strtok_usual");
  tcase_add_test(tc_strtok_usual, test_s21_string_strtok_usual);
  suite_add_tcase(s, tc_strtok_usual);

  tc_strtok_unusual = tcase_create("strtok_unusual");
  tcase_add_test(tc_strtok_unusual, test_s21_string_strtok_unusual);
  suite_add_tcase(s, tc_strtok_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_strtok_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
