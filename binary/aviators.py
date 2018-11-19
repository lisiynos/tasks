# -*- coding: utf-8 -*-
# Отважные воздухоплаватели
from __future__ import print_function

import sys

ID = 'aviators'
sys.stdin = open(ID + ".in", "r")
# sys.stdout = open(ID + ".out", "w")

# Считываем исходные данные
N = 10
MAX = 10000
A = [0] * N
for i in range(N):
    A[i] = int(input())
    assert 1 <= A[i] <= MAX

P = [0] * (MAX + 1)  # Количество делителей с заданным значением
for x in A:
    for d in range(2, round(x ** 0.5) + 1):
        while x % d == 0:
            P[d] += 1
            x //= d
    if x > 1:
        P[x] += 1

# Формирование ответа
ans = 1
for v in P:
    ans = ans * (v + 1) % 10
print(ans)
