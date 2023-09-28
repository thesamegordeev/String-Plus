#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_trim_usual) {
  char src1[100] = "-=*asdf111 *-= ";
  char trim_chars1[100] = "-=* ";
  char res1[30] = "asdf111";
  char *test1 = s21_trim(src1, trim_chars1);
  ck_assert_str_eq(test1, res1);
  char src2[100] = "q a s f v";
  char trim_chars2[100] = "qa ";
  char res2[30] = "s f v";
  char *test2 = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(test2, res2);
  char src3[100] = "";
  char trim_chars3[100] = "qa ";
  char *test3 = s21_trim(src3, trim_chars3);
  ck_assert_str_eq(test3, "");
  char *src5 = NULL;
  char trim_chars5[100] = "qa ";
  char *test5 = s21_trim(src5, trim_chars5);
  ck_assert_ptr_null(test5);
  if (test1 != NULL) {
    printf("test1");
    fflush(stdout);
    free(test1);
  }
  if (test2 != NULL) {
    printf("test2");
    fflush(stdout);
    free(test2);
  }
  if (test3 != NULL) {
    printf("test3");
    fflush(stdout);
    free(test3);
  }
  if (test5 != NULL) {
    printf("test5");
    fflush(stdout);
    free(test5);
  }
}
END_TEST

Suite *s21_trim_suite() {
  Suite *s;
  TCase *tc_trim_usual, *tc_trim_unusual;

  s = suite_create("trim");

  tc_trim_usual = tcase_create("trim_usual");
  tcase_add_test(tc_trim_usual, test_s21_trim_usual);
  suite_add_tcase(s, tc_trim_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_trim_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
