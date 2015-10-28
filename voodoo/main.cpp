#include <iostream>
#include <stdio.h>
#include <vector>

#define FN "voodoo"

using namespace std;

/*
int pow(int x, int y) {
  int res = x;
  for(int i = 2; i <= y; i++)
    res *= x;
  return res;
}*/

typedef long long ll;

int n; // Количество кристаллов
vector<ll> p; // Сила кристаллов
const ll MOD = 1 << 30; // 2^30
// (число) << (кол-во бит)

int main() {
  freopen(FN".in", "r", stdin);
  freopen(FN".out", "w", stdout);
  // Чтение входных данных
  cin >> n;
  p.resize(n);
  for(int i = 0; i < n; i++)
    cin >> p[i];

  // Перебираем все подмножества из
  // n элементов
  // 0..(2^n)-1
  // Например, если 3 элемента a,b,c:
  // 0..(2^3)-1 = 7
  // abc
  // 000  []
  // 001  [c]
  // 010  [b]
  // 011  [b,c]
  // 100  [a]
  // 101  [a,c]
  // 110  [a,b]
  // 111  [a,b,c]
  int high = (1 << n) - 1;
  // (1 << n) - сдвинуть 1 на n бит влево
  //  001
  // 1000 - 1
  //  111
  // Максимальная сила кристаллов
  ll maxPower = -100500;
  for(int s = 1; s <= high; s++) {
    ll p1 = 1; // Суммарная сила
    // Цикл по кристаллам
    for(int i = 0; i < n; i++)
      // Установлен ли i-ый бит в s
      if((s >> i) & 1)
        p1 = (p1 * p[i]) % MOD;
    // Подсчитали суммарную силу
    maxPower = max(maxPower, p1);
  }
  // Выводим ответ
  //cout << MOD << endl;
  cout << maxPower << endl;

  return 0;
}
