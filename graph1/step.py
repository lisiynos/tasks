# -*- coding: utf-8 -*-
# DFS = Depth First Search - Поиск в глубину - Обход в глубину
# Задача "Пошаговый обход графа"
import sys

NAME = "step"
sys.stdin = open(NAME + ".in", "r")
sys.stdout = open(NAME + ".out", "w")

N, M, v = map(int, input().split())
used = [False] * (N + 1)

# считываем рёбра графа
A = [[False] * (N + 1) for i in range(N + 1)]
for k in range(M):
    i, j = map(int, input().split())
    A[i][j] = True
    A[j][i] = True


# i - текущая вершина
def go(i):
    used[i] = True  # посетили
    path.append(i)  # добавили в путь
    # j - следующая вершина
    for j in range(1, N + 1):
        # Если ещё не были в j и можем перейти
        if not used[j] and A[i][j]:
            go(j)  # идём
            path.append(i)  # вернулись


# путь
path = []
go(v)
# выводим путь
print(len(path))
print(*path)
