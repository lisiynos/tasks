#include <iostream>
#include <stdio.h>
#include <vector>

#define FN "traps"

using namespace std;

int n; // Количество комнат
int m; // Количество коридоров
vector<vector<int> > e; // Переходы
int ans = 0; // Количество тупиков
vector<bool> used; // Посетили ли мы эту вершину?

// Поиск в глубину
void dfs(int v) {
  used[v] = true; // Посетили вершину v
  bool trap = (v != 1); // Ловушка
  for(int i = 0; i < e[v].size(); i++) {
    int u = e[v][i];
    if(!used[u]) {
      // Если есть куда идти,
      // то это не ловушка
      trap = false;
      dfs(u);
    }
  }
  if(trap)
    ans++;
}

int main() {
  freopen(FN".in", "r", stdin);
  freopen(FN".out", "w", stdout);
  // Чтение входных данных
  cin >> n >> m;
  e.resize(n + 1);
  used.resize(n + 1, false);
  // Читаем m коридоров
  for(int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    e[v].push_back(u);
    e[u].push_back(v);
  }
  // Обход дерева
  dfs(1);
  // Выводим ответ
  cout << ans << endl;

  /*vector<int> v;
  v.push_back(10);
  v.size(); // Размер вектора
  for(int i = 0; i < v.size(); i++)
    v[i] = 10;  cout << v[i] << endl; */

  return 0;
}
