#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strstr_usual) {
  char *str_1 = "aabaagfbaaccaadcaaabbaabf";
  char *subdStr_1 = "aab";
  char *subdStr_2 = "aa";
  char *subdStr_3 = "abf";
  ck_assert_pstr_eq(s21_strstr(str_1, subdStr_1), strstr(str_1, subdStr_1));
  ck_assert_pstr_eq(s21_strstr(str_1, subdStr_2), strstr(str_1, subdStr_2));
  ck_assert_pstr_eq(s21_strstr(str_1, subdStr_3), strstr(str_1, subdStr_3));
}
END_TEST

START_TEST(test_s21_string_strstr_unusual) {
  char *str_1 = "aabaagfbaaccaadcaaabbaabf";
  char *str_2 = "";
  char *subdStr_1 = "ggg";
  char *subdStr_2 = "";
  char *subdStr_3 = "abf";
  ck_assert_pstr_eq(s21_strstr(str_1, subdStr_2), strstr(str_1, subdStr_2));
  ck_assert_ptr_null(s21_strstr(str_1, subdStr_1));
  ck_assert_ptr_null(s21_strstr(str_2, subdStr_2));
}
END_TEST

Suite *s21_strstr_suite() {
  Suite *s;
  TCase *tc_strstr_usual, *tc_strstr_unusual;

  s = suite_create("strstr");

  tc_strstr_usual = tcase_create("strstr_usual");
  tcase_add_test(tc_strstr_usual, test_s21_string_strstr_usual);
  suite_add_tcase(s, tc_strstr_usual);

  tc_strstr_unusual = tcase_create("strstr_unusual");
  tcase_add_test(tc_strstr_unusual, test_s21_string_strstr_unusual);
  suite_add_tcase(s, tc_strstr_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_strstr_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
