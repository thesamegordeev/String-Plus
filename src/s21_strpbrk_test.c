#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_strpbrk_usual1) {
  char str1[5] = "abcd";
  char str2[3] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual2) {
  char str1[5] = "abcd";
  char str2[3] = "efg";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual3) {
  char str1[5] = "abcd";
  char str2[10] = "eeeeeeeeee";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual4) {
  char str1[5] = "abcd";
  char str2[5] = "ccccc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual5) {
  char str1[5] = "abcd";
  char str2[3] = "cba";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual6) {
  char str1[1] = "a";
  char str2[1] = "a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual7) {
  char str1[1] = "a";
  char str2[3] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual8) {
  char str1[1] = "a";
  char str2[1] = "b";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual9) {
  char str1[5] = "abcd";
  char str2[3] = "eea";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual10) {
  char str1[5] = "abcd";
  char str2[3] = "eeb";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual11) {
  char str1[5] = "abcd";
  char str2[3] = "eed";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_string_strpbrk_usual12) {
  char str1[5] = "abcd";
  char str2[1] = "a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_strpbrk_usual;

  s = suite_create("strpbrk");

  tc_strpbrk_usual = tcase_create("strpbrk_usual");
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual1);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual2);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual3);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual4);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual5);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual6);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual7);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual8);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual9);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual10);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual11);
  tcase_add_test(tc_strpbrk_usual, test_s21_string_strpbrk_usual12);
  suite_add_tcase(s, tc_strpbrk_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_pow_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
