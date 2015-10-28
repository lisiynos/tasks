// Задача E: Древнее волшебство
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>

#define FN "ancient"

//#define DEBUG

#ifdef DEBUG
#define S(x) cout << #x << " = " << x << endl;
#else
#define S(x)
#endif

using namespace std;

int main() {
  freopen(FN".in", "r", stdin);
#ifndef DEBUG
  freopen(FN".out", "w", stdout);
#endif

  // Чтение входных данных
  string z; // Заклинание
  // getline(cin, z)
  cin >> z;
  string magic; // Волшебное слово
  cin >> magic;

  // Двухмерный динамический массив
  /* int** res = new int*[z.size()];
   for(int i = 0; i < z.size(); i++){
     res[i] = new int[magic.size()];
     for(int j = 0; j < magic.size(); j++)
       res[i][j] = -1;
   } */
  //     a  b  a  z  a  b  a
  //  a  1  1  2  2  3  3  4
  //  z  0  0  0  2  2  2  2
  long long res[magic.size()][z.size()];
  memset(res, 0, sizeof(res));
  // Количество вхождений и скрытых и не
  // скрытых
  if(magic[0] == z[0])
    res[0][0] = 1;
  // Обрабатываем первый символ магического слова
  for(int j = 1; j < z.size(); j++)
    res[0][j] = res[0][j - 1] +
                (z[j] == magic[0]);
  // Вычисляем все остальные строчки
  for(int i = 1; i < magic.size(); i++)
    for(int j = 1; j < z.size(); j++) {
      res[i][j] = res[i][j - 1];
      if(magic[i] == z[j] && j >= 2)
        res[i][j] += res[i - 1][j - 2];
    }

#ifdef DEBUG
  cout << "  ";
  for(int j = 0; j < z.size(); j++)
    cout << z[j] << " ";
  cout << endl;
  for(int i = 0; i < magic.size(); i++) {
    cout << magic[i] << " ";
    for(int j = 0; j < z.size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
#endif // DEBUG

  // Вывод ответа
  cout << res[magic.size() - 1][z.size() - 1]
       << endl;

  return 0;
}
