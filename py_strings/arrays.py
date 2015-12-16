# -*- utf-8 -*-
# Пример создания двумерного массива на Python
N = 10
# 2D массив 10x10
a = [[0] * N for x in range(N)]
for i in range(N):
    for j in range(N):
        a[i][j] = i * j
print(a)
