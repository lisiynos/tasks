# -*- coding: utf-8 -*-
from __future__ import print_function

# input() python 2/3 compatibility
try:
    input = raw_input
except NameError:
    pass

import sys

ID = 'comb2'
sys.stdin = open(ID + ".in", "r")
# sys.stdout = open(ID + ".out", "w")

res = {}


# Количество сочетаний с n, k и первым числом d
def C(n, k, d):
    assert 1 <= d <= n
    if k == 1:  # Из одного элемента с одной цифрой - один вариант
        return 1
    if (n, k, d) not in res:  # Если не считали - считаем
        res[n, k, d] = sum(C(n, k - 1, t) for t in range(d, n + 1))
    return res[n, k, d]


# Сочетание с повторениями
def F(n, k, x):
    answer = []
    start = 1
    for i in range(k):  # Идём по длине комбинации
        for d in range(start, n + 1):  # Перебираем цифру
            c = C(n, k - i, d)  # Пропускаем группы
            if x >= c:
                x -= c
            else:
                answer.append(d)
                start = d
                break
    return answer


assert C(1, 1, 1) == 1
assert C(3, 2, 1) == 3  # (1,1) (1,2) (1,3)
assert C(3, 2, 2) == 2  # (2,2) (2,3)
assert C(3, 2, 3) == 1  # (3,3)
assert F(3, 2, 0) == [1, 1]
assert F(3, 2, 1) == [1, 2]
assert F(3, 2, 2) == [1, 3]
assert F(3, 2, 3) == [2, 2]
assert F(3, 2, 4) == [2, 3]
assert F(3, 2, 5) == [3, 3]
assert F(1, 1, 0) == [1]

assert C(4, 2, 1) == 4  # (1,1) (1,2) (1,3) (1,4)
assert C(4, 2, 2) == 3  # (2,2) (2,3) (2,4)
assert C(4, 2, 3) == 2  # (3,3) (3,4)
assert C(4, 2, 4) == 1  # (4,4)

n, k, x = map(int, input().split())
print(*F(n, k, x))
