/// Побитовые операции
/// ------------------
/// * И - AND - &   если 1 и 1, то 1, иначе 0
/// * ИЛИ - OR - |   0 только если оба 0
/// * НЕ - NOT - ~   0 -> 1,  1 -> 0
/// * Исключающее ИЛИ - XOR - ^
/// не равно, или один или второй,
/// но не оба сразу
/// * >> - сдвиг вправо
/// * << - сдвиг влево
#include <iostream>

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

using namespace std;

int main() {
  cout << "== AND ==" << endl;
  SHOW(0 & 0);
  SHOW(0 & 1);
  SHOW(1 & 0);
  SHOW(1 & 1);

  cout << "== OR ==" << endl;
  SHOW(0 | 0);
  SHOW(0 | 1);
  SHOW(1 | 0);
  SHOW(1 | 1);

  // Исключающее ИЛИ
  // Или первый или второй, но не оба сразу
  cout << "== XOR ==" << endl;
  SHOW(0 ^ 0);
  SHOW(0 ^ 1);
  SHOW(1 ^ 0);
  SHOW(1 ^ 1);

  cout << "== NOT ==" << endl;
  SHOW(~0); // -1
  SHOW(~1); // -2

  // Сдвиг влево (умножение на 2)
  SHOW(1 << 1);
  SHOW(1 << 2);
  SHOW(1 << 3);
  SHOW(1 << 4);

  // Перебор всех подмножеств из N элементов
  int N = 3;
  for(int i = 0; i < (1 << N); i++) {
    for(int bit = 0; bit < N; bit++)
      if((i >> bit) & 1) //
        cout << (bit + 1) << " ";
    cout << endl;
  }

  return 0;
}
