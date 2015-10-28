/// Работа со строками
/// ==================
#include <iostream>
#include <string.h> // C
#include <string> // C++

using namespace std;

// SHOW
#define S(x) cout << #x << " = " << x << endl;

int main() {
  // C строки
  {

    char s[1000] = "test"; // s - имя переменной
    // 1000 количество символов
    // Строки заканчиваются на
    // символ с кодом 0
    //cin >> s; // Ввод строки
    S(strlen(s)); // Длина строки
    S(strcmp(s, "test")); // Сравнение
    S(strcmp("test", "a")); // 1
    S(strcmp("test", "z")); // -1
    S(strcmp("test", "ta")); // 1
    S(strcmp("test", "tz")); // -1
    // Строки равны
    if(!strcmp("test","test"))
      cout << "!! TRUE !!" << endl;
    for(int i = 0; i < strlen(s); i++)
      cout << "s[" << i << "] = "
           << s[i] << endl;
    S((char)tolower('T'));
  }

  // C++ строчки
  string s = "Test";
  s[0] = '#';
  S(s);
  // Получение подстроки
  // substr(начало, длина)
  S(s.substr(1, 2));

  // Добавляю в конец
  s.append("Trali-vali :)");
  S(s);
  // Добавить символы
  s.append(5, '#');
  S(s);

  // Добавить первые 4 символа
  // из строки "123456"
  s.append("123456", 4);
  S(s);

  // Обрезаем до 10 символов
  s.resize(10);
  S(s);
  s.replace(2, 2, "[!!!!]");
  S(s);

  S(s.size()); // Длина строки
  // http://ru.cppreference.com/w/

  return 0;
}
