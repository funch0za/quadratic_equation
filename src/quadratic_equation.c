#include "../include/quadratic_equation.h"

/**
 * @brief Проверяет подходит ли число для вычислений
 * @param {double} x - число для проверки
 * @return {bool} :
                true - число подходит
                false - число не подходит
 */
bool num_is_ok(double x) {
  return fpclassify(x) == FP_ZERO || fpclassify(x) == FP_NORMAL;
}

/**
 * @brief Решает уравнение ax^2+bx+c=0
 * @param {double} a - коэффициент уравнения
 * @param {double} b - коэффициент уравнения
 * @param {double} c - коэффициент уравнения
 * @param {double} *x1 - будет записано одно из решений уравнения
 * @param {double} *x2 - будет записано одно из решений уравнения
 * @return {eq_status_t} - возвращает значение одной из констант: бесконечное
 * кол-во решений, два решения, одно решение, нет решение, ошибка
 */
eq_status_t solve_equation(double a, double b, double c, double *x1,
                           double *x2) {
  eq_status_t status;

  if (num_is_ok(a) && num_is_ok(b) && num_is_ok(c)) {
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
