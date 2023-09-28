#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_memcmp_usual1) {
  char str1[5] = "abcd\0";
  char str2[5] = "gggg\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual2) {
  char str1[5] = "abcd\0";
  char str2[5] = "abcd\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual3) {
  char str1[5] = "abcd\0";
  char str2[5] = "abcd";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual4) {
  char str1[5] = "abcd\0";
  char str2[5] = "abc\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual5) {
  char str1[5] = "abcc\0";
  char str2[5] = "abcd\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual6) {
  char str1[5] = "abcd\0";
  char str2[5] = "abcc\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual7) {
  char str1[5] = "abcd\0";
  char str2[5] = "abce\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual8) {
  char str1[5] = "abc\0";
  char str2[5] = "abcd\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

START_TEST(test_s21_string_memcmp_usual9) {
  char str1[5] = "1\0";
  char str2[5] = "1\0";
  int sign1 = memcmp(str1, str2, 5);
  int sign2 = s21_memcmp(str1, str2, 5);
  ck_assert((sign1 < 0 && sign2 < 0) || (sign1 == 0 && sign2 == 0) ||
            (sign1 > 0 && sign2 > 0));
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_memcmp_usual;

  s = suite_create("memcmp");

  tc_memcmp_usual = tcase_create("memcmp_usual");
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual1);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual2);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual3);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual4);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual5);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual6);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual7);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual8);
  tcase_add_test(tc_memcmp_usual, test_s21_string_memcmp_usual9);
  suite_add_tcase(s, tc_memcmp_usual);

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
