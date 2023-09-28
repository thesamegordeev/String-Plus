#include <check.h>
#include <string.h>

#include "s21_string.h"

char *s21_strchr(const char *str, int c);

START_TEST(test_s21_string_strchr_usual1) {
  char *str = "abobus";
  ck_assert_pstr_eq(s21_strchr(str, 's'), strchr(str, 's'));
}
END_TEST

START_TEST(test_s21_string_strchr_usual2) {
  char *str = "Gref help pls, Verter si awful!!!";
  ck_assert_pstr_eq(s21_strchr(str, 's'), strchr(str, 's'));
}
END_TEST

START_TEST(z_line) {
  char str[6] = {65, 66, 79, 66, 85, 83};
  ck_assert_pstr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(empty_str) {
  char *str = "";
  ck_assert_pstr_eq(s21_strchr(str, 's'), strchr(str, 's'));
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *s;
  TCase *tc_strchr_normal = tcase_create("strchr_normal");

  s = suite_create("strchr");
  tcase_add_test(tc_strchr_normal, test_s21_string_strchr_usual1);
  tcase_add_test(tc_strchr_normal, test_s21_string_strchr_usual2);
  tcase_add_test(tc_strchr_normal, z_line);
  tcase_add_test(tc_strchr_normal, empty_str);
  suite_add_tcase(s, tc_strchr_normal);
  return s;
}

int main(void) {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_strchr_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
