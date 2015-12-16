#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define TASK "police"

double sqr(double x) {
  return x * x;
}

// (xc - x3)^2 + (yc - y3)^2 = R^2
// (xc - x1)^2 + (yc - y1)^2 = R^2
// Уравнения сложные
// Переместим начало координат в x1,y1
//   x3 -= x1;   y3 -= y1;
// (R - x3)^2 + y3^2 = R^2
// R^2 - 2Rx3 + x3^2 + y3^2 = R^2
// - 2Rx3 + x3^2 + y3^2 = 0
//  + x3^2 + y3^2 = 2Rx3
//  R = (x3^2 + y3^2) / (2x3)

double solve(double x3, double y3) {
  return (sqr(x3) + sqr(y3)) / (2.0 * x3);
}

int main() {
  freopen(TASK ".in", "r", stdin);
#ifndef MYCOMP
  freopen(TASK ".out", "w", stdout);
#endif
  double x1, y1, x2, y2, x3, y3;
  // Вводим из входного файла
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  // Перемещаем начало координат в x1, y1
  x3 -= x1;
  y3 -= y1;
  // Вектор движения пиратского корабля
  double dx = x2 - x1;
  double dy = y2 - y1;

  double EPS = 1e-12;
  double l = 0.0, r = 50000.0;
  double R, t;
  while(fabs(r - l) > EPS) {
    t = (l + r) / 2.0;
    double xp = t * dx;
    double yp = t * dy;
    R = sqrt(sqr(xp - x3) +
             sqr(yp - y3));
    if(R >= t)
      l = t;
    else
      r = t;
  }
  if(fabs(R - t) < EPS) {
#ifdef MYCOMP
    cout << "R = " << R << "  t = " << t << endl;
    cout << x3 << " " << y3 << endl;
#endif
    cout << t << endl;
    return 0;
  }

  cout << "-1" << endl;

  return 0;
}
