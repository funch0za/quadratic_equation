#include "../include/quadratic_equation.h"
#include <check.h>

#define EPS 1e-6

START_TEST(test1) {
  double x1, x2;

  double a = 3, b = -4, c = 10;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(test2) {
  double x1, x2;

  double a = 2, b = 12, c = 2;
  eq_status_t status = solve_equation(2, 12, 2, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test3) {
  double x1, x2;

  double a = 43, b = 76, c = -79;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test4) {
  double x1, x2;

  double a = NAN, b = 2, c = 3;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_ERROR);
}
END_TEST

START_TEST(test5) {
  double x1, x2;

  double a = 0, b = 0, c = 0;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(x1, 1);
  ck_assert_int_eq(x2, 1);
  ck_assert_int_eq(status, EQ_INF_SOLUTION);
}
END_TEST

START_TEST(test6) {
  double x1, x2;

  double a = 0, b = 0, c = 1;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(test7) {
  double x1, x2;

  double a = INFINITY, b = NAN, c = -1;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_ERROR);
}
END_TEST

START_TEST(test8) {
  double x1, x2;

  double a = 0.000331, b = 0.001434, c = 0.000351;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test9) {
  double x1, x2;

  double a = -0.000164, b = 0.000291, c = 0.000927;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test10) {
  double x1, x2;

  double a = 1e5, b = 1e5, c = 1e-5;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test11) {
  double x1, x2;

  double a = EPS, b = EPS, c = 0;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  double value_x1 = a * x1 * x1 + b * x1 + c;
  double value_x2 = a * x2 * x2 + b * x2 + c;

  ck_assert_double_ge(EPS, value_x1);
  ck_assert_double_ge(EPS, value_x2);
  ck_assert_int_eq(status, EQ_TWO_SOLUTION);
}
END_TEST

START_TEST(test12) {
  double x1, x2;

  double a = EPS, b = EPS, c = 10;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(test13) {
  double x1, x2;

  double a = 0.1, b = 0.003, c = 0.002;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

int main() {
  Suite *s = suite_create("quadratic_equation");
  TCase *tc_core = tcase_create("core");
  SRunner *sr = srunner_create(s);

  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, test1);
  tcase_add_test(tc_core, test2);
  tcase_add_test(tc_core, test3);
  tcase_add_test(tc_core, test4);
  tcase_add_test(tc_core, test5);
  tcase_add_test(tc_core, test6);
  tcase_add_test(tc_core, test7);
  tcase_add_test(tc_core, test8);
  tcase_add_test(tc_core, test9);
  tcase_add_test(tc_core, test10);
  tcase_add_test(tc_core, test11);
  tcase_add_test(tc_core, test12);
  tcase_add_test(tc_core, test13);

  srunner_run_all(sr, CK_ENV);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);
}
