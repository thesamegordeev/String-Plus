#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_insert_usual) {
  char src1[100] = "aaabbb";
  char str1[100] = "!!!";
  char res1[30] = "aaa!!!bbb";
  ck_assert_str_eq(s21_insert(src1, str1, 3), res1);
  char src2[100] = "aaabbb";
  char str2[100] = "";
  char res2[30] = "aaabbb";
  ck_assert_str_eq(s21_insert(src2, str2, 4), res2);
  char src3[100] = "";
  char str3[100] = "!!!";
  ck_assert_ptr_null(s21_insert(src3, str3, 3));
  // char src4[100] = "";
  // char str4[100] = "";
  // ck_assert_ptr_null(s21_insert(src4, str4, 0));
  char src5[100] = "aaabbb";
  char str5[100] = "!!!";
  char res5[30] = "!!!aaabbb";
  ck_assert_str_eq(s21_insert(src5, str5, 0), res5);
}
END_TEST

Suite *s21_insert_suite() {
  Suite *s;
  TCase *tc_insert_usual;

  s = suite_create("insert");

  tc_insert_usual = tcase_create("insert_usual");
  tcase_add_test(tc_insert_usual, test_s21_insert_usual);
  suite_add_tcase(s, tc_insert_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_insert_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
