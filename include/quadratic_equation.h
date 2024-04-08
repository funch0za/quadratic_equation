#include <math.h>
#include <stdbool.h>

enum {
  EQ_INF_SOLUTION = 3,
  EQ_TWO_SOLUTION = 2,
  EQ_ONE_SOLUTION = 1,
  EQ_NO_SOLUTION = 0,
  EQ_ERROR = -1,
};

typedef int eq_status_t;

// Функция проверяет что число не NAN и не бесконечность
bool num_is_normal(double x);

// Функция решает квадратное уравнение ax^2+bx+c=0
eq_status_t solve_equation(double a, double b, double c, double *x1,
                           double *x2);
