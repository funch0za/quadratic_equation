#include "../include/quadratic_equation.h"
#include <check.h>
#include <stdlib.h>

#define EPS 1e-6

START_TEST(num_is_ok1) {
  ck_assert(num_is_ok(1.001));
  ck_assert(num_is_ok(-123));
  ck_assert(num_is_ok(333));
  ck_assert(num_is_ok(0.000001));
  ck_assert(num_is_ok(EPS));
}
END_TEST

START_TEST(num_is_ok2) {
  ck_assert(!num_is_ok(NAN));
  ck_assert(!num_is_ok(INFINITY));
}
END_TEST

START_TEST(solve_equation1) {
  double x1, x2;

  double a = 3, b = -4, c = 10;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(solve_equation2) {
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

START_TEST(solve_equation3) {
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

START_TEST(solve_equation4) {
  double x1, x2;

  double a = NAN, b = 2, c = 3;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_ERROR);
}
END_TEST

START_TEST(solve_equation5) {
  double x1, x2;

  double a = 0, b = 0, c = 0;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(x1, 1);
  ck_assert_int_eq(x2, 1);
  ck_assert_int_eq(status, EQ_INF_SOLUTION);
}
END_TEST

START_TEST(solve_equation6) {
  double x1, x2;

  double a = 0, b = 0, c = 1;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(solve_equation7) {
  double x1, x2;

  double a = INFINITY, b = NAN, c = -1;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_ERROR);
}
END_TEST

START_TEST(solve_equation8) {
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

START_TEST(solve_equation9) {
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

START_TEST(solve_equation10) {
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

START_TEST(solve_equation11) {
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

START_TEST(solve_equation12) {
  double x1, x2;

  double a = EPS, b = EPS, c = 10;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

START_TEST(solve_equation13) {
  double x1, x2;

  double a = 0.1, b = 0.003, c = 0.002;
  eq_status_t status = solve_equation(a, b, c, &x1, &x2);

  ck_assert_int_eq(status, EQ_NO_SOLUTION);
}
END_TEST

Suite *num_is_ok_suite() {
  Suite *suite = suite_create("num_is_ok");
  TCase *tc_core = tcase_create("core_of_num_is");

  tcase_add_test(tc_core, num_is_ok1);
  tcase_add_test(tc_core, num_is_ok2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *solve_equation_suite() {
  Suite *suite = suite_create("solve_equation");
  TCase *tc_core = tcase_create("core_of_solve_equation");

  tcase_add_test(tc_core, solve_equation1);
  tcase_add_test(tc_core, solve_equation2);
  tcase_add_test(tc_core, solve_equation3);
  tcase_add_test(tc_core, solve_equation4);
  tcase_add_test(tc_core, solve_equation5);
  tcase_add_test(tc_core, solve_equation6);
  tcase_add_test(tc_core, solve_equation7);
  tcase_add_test(tc_core, solve_equation8);
  tcase_add_test(tc_core, solve_equation9);
  tcase_add_test(tc_core, solve_equation10);
  tcase_add_test(tc_core, solve_equation11);
  tcase_add_test(tc_core, solve_equation12);
  tcase_add_test(tc_core, solve_equation13);

  suite_add_tcase(suite, tc_core);

  return suite;
}

unsigned int run_suite(Suite *suite, char *file_logs) {
  SRunner *srunner = srunner_create(suite);

  srunner_set_log(srunner, file_logs);
  srunner_run_all(srunner, CK_ENV);
  int count_failed_tests = srunner_ntests_failed(srunner);

  srunner_free(srunner);

  return count_failed_tests;
}

int main() {
  int count_failed_tests = 0;
  
  count_failed_tests +=
      run_suite(num_is_ok_suite(), "test/logs/test_num_is_ok.log");
  count_failed_tests += run_suite(solve_equation_suite(),
                                  "test/logs/test_solve_equation_suite.log");

  return count_failed_tests == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
