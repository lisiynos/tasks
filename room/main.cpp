#include <iostream>
#include <stdio.h>

#define FN "room"

using namespace std;

struct Point {
  int x, y;
};

const int MIN = 1, MAX = 44;

// Целое число в квадрате
int sqr(int x) {
  return x * x;
}

// Расстояние между точками равно длине отрезка
// true - если равно
// false - если не равно
bool lenEquals(Point& A, Point& B, int l) {
  return (sqr(A.x - B.x) + sqr(A.y - B.y)) ==
         sqr(l);
}

// !!! MAGIC STARTS HERE
// vvvvvvvvv
// <--
// Округление
// floor - в меньшую
// ceil - в большую сторону
int main() {
  freopen(FN".in", "r", stdin);
  freopen(FN".out", "w", stdout);
  int a, b, c; // Стороны треугольника
  Point A, B, C; // Вершины треугольника
  cin >> a >> b >> c;

  int cnt = 0;
  for(A.x = MIN; A.x <= MAX; A.x++)
    for(A.y = MIN; A.y <= MAX; A.y++)
      for(B.x = MIN; B.x <= MAX; B.x++)
        for(B.y = MIN; B.y <= MAX; B.y++)
          if(lenEquals(A, B, a))
            for(C.x = MIN; C.x <= MAX; C.x++)
              for(C.y = MIN; C.y <= MAX; C.y++) {
                cnt++;
                if(lenEquals(A, C, b) &&
                    lenEquals(B, C, c)) {
                  cout << "YES" << endl;
                  cout << A.x << " " << A.y << endl;
                  cout << B.x << " " << B.y << endl;
                  cout << C.x << " " << C.y << endl;
                  //cout << "cnt = " << cnt << endl;
                  return 0;
                }
              }
  cout << "NO" << endl;
  //cout << "cnt = " << cnt << endl;
  return 0;
}
