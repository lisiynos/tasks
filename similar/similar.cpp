#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Точка с целыми координатами
struct Point {
  int x, y;
};

// Квадрат целого числа
int sqr(int x) {
  return x * x;
}

// Треугольник
struct Triangle {
  Point p[3]; // Три точки
  int S[3]; // Квадраты длин сторон
  // Чтение треугольника
  void read() {
    for(int i = 0; i < 3; i++)
      cin >> p[i].x >> p[i].y;
  }
  // Вычисляем длины квадратов сторон
  void calc() {
    for(int i = 0; i < 3; i++) {
      int j = (i + 1) % 3; // Следующая точка
      S[i] = sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);
    }
  }
};

// 2 треугольника
Triangle T1, T2;

// Пропорциональны ли стороны i и j
bool pr(int i, int j) {
  return T1.S[i] * T2.S[j] == T1.S[j] * T2.S[i];
}

int main() {
  freopen("similar.in", "r", stdin);
#ifndef DEBUG
  freopen("similar.out", "w", stdout);
#endif
  // Количество тестов
  int n;
  cin >> n;

  // Цикл по тестам
  for(int t = 0; t < n; t++) {
    // Считываем 2 треугольника
    T1.read();
    T2.read();

    // Квадраты длин сторон
    T1.calc();
    T2.calc();

    if(pr(0, 1) && pr(1, 2) && pr(0, 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
