#include "../include/quadratic_equation.h"

bool num_is_normal(double x) {
  return fpclassify(x) == FP_ZERO || fpclassify(x) == FP_NORMAL;
}

eq_status_t solve_equation(double a, double b, double c, double *x1,
                           double *x2) {
  eq_status_t status;

  if (num_is_normal(a) && num_is_normal(b) && num_is_normal(c)) {
    status = EQ_ERROR;
    if (a == 0) {
      if (b == 0) {
        if (c == 0) {
          status = EQ_INF_SOLUTION;
          *x1 = 1;
          *x2 = 1;
        } else {
          status = EQ_NO_SOLUTION;
        }
      } else if (c == 0) {
        status = EQ_ONE_SOLUTION;
        *x1 = 0;
      } else {
        status = EQ_ONE_SOLUTION;
        *x1 = -b / c;
      }
    } else {
      double D = b * b - 4 * a * c;

      if (D < 0) {
        status = EQ_NO_SOLUTION;
      } else {
        *x1 = (-b + sqrt(D)) / (2 * a);
        if (D == 0) {
          status = EQ_ONE_SOLUTION;
        } else {
          status = EQ_TWO_SOLUTION;
          *x2 = (-b - sqrt(D)) / (2 * a);
        }
      }
    }
  } else {
    status = EQ_ERROR;
  }

  return status;
}
