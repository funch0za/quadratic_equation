#include <math.h>
#include <stdbool.h>

enum {
  // Бесконечное кол-во решений
  EQ_INF_SOLUTION = 3,
  // Два решения
  EQ_TWO_SOLUTION = 2,
  // Одно решение
  EQ_ONE_SOLUTION = 1,
  // Нет решений
  EQ_NO_SOLUTION = 0,
  // Во время работы функции произошла ошибка
  EQ_ERROR = -1,
};

// Статус решения квадратного уравнения
typedef int eq_status_t;

// Функция проверяет что число не NAN и не бесконечность
bool num_is_ok(double x);

// Функция решает квадратное уравнение ax^2+bx+c=0
eq_status_t solve_equation(double a, double b, double c, double *x1,
                           double *x2);
