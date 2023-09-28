#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strncpy_usual) {
  char *src = "Hello, world!\0";
  char dst[14];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 14), strncpy(dst, src, 14));
}
END_TEST

START_TEST(test_s21_string_strncpy_usual2) {
  char *src = "Hello, world!\0";
  char dst[25];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 25), strncpy(dst, src, 25));
}
END_TEST

START_TEST(test_s21_string_strncpy_usual4) {
  char *src = "Hello, world!";
  char dst[25];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 20), strncpy(dst, src, 20));
}
END_TEST

START_TEST(test_s21_string_strncpy_usual3) {
  char *src = "Hello, world!\0	";
  char dst[14];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 5), strncpy(dst, src, 5));
}
END_TEST

START_TEST(test_s21_string_strncpy_unusual) {
  char src[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
  char dst[6];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 6), strncpy(dst, src, 6));

  char src_e[6] = {};
  char dst_e[6];
  ck_assert_pstr_eq(s21_strncpy(dst_e, src_e, 6), strncpy(dst_e, src_e, 6));
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *s;
  TCase *tc_strncpy_usual, *tc_strncpy_unusual;

  s = suite_create("strncpy");

  tc_strncpy_usual = tcase_create("strncpy_usual");
  tcase_add_test(tc_strncpy_usual, test_s21_string_strncpy_usual);
  tcase_add_test(tc_strncpy_usual, test_s21_string_strncpy_usual2);
  tcase_add_test(tc_strncpy_usual, test_s21_string_strncpy_usual3);
  tcase_add_test(tc_strncpy_usual, test_s21_string_strncpy_usual4);
  suite_add_tcase(s, tc_strncpy_usual);

  tc_strncpy_unusual = tcase_create("strncpy_unusual");
  tcase_add_test(tc_strncpy_unusual, test_s21_string_strncpy_unusual);
  suite_add_tcase(s, tc_strncpy_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_strncpy_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
