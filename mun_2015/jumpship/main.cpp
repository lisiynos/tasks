#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define TASK "jumpship"

int d[4] = {3, -3, 5, -5};

int main() {
  freopen(TASK ".in", "r", stdin);
#ifndef MYCOMP
  freopen(TASK ".out", "w", stdout);
#endif
  // Вводим из входного файла a и b
  int a, b;
  cin >> a >> b;
  // Посещена ли вершина
  // 0 - не посещена
  // 3,-3,5,-5 - каким ходом её посетили
  // -1 - были с самого начала
  int visited[101];
  int time[101];
  for(int i = 0; i <= 100; i++) {
    visited[i] = 0;
    time[i] = 100500;
  }
  // Моделирование по времени
  visited[a] = -1;
  time[a] = 0;
  int t;
  for(t = 0; !visited[b]; t++) {
    for(int v = 1; v <= 100; v++) {
      if(time[v] == t) {
        // v - откуда идём
        for(int i = 0; i < 4; i++) {
          int move = d[i];
          int u = v + move;
          if(u < 1 || u > 100) continue;
          if(visited[u] != 0) continue;
          // Запоминаем как мы сюда пришли
          visited[u] = move;
          time[u] = time[v] + 1;
        }
      }
    }
  }
  // Восстанавливаем ответ
  cout << t << endl;
  int cur = b; // Сейчас мы в b
  for(int i = 0; i < t; i++) {
    // Пишем как мы попали в cur
    cout << visited[cur] << endl;
    // Переходим назад
    cur = cur - visited[cur];
    // Например, если мы сейчас в 5
    // и visited[5] = -5
    // Значит, мы пришли из 10
  }
  return 0;
}
