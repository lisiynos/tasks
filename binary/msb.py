# -*- coding: utf-8 -*-
# Поиск самой левой единички в битовом представлении числа

# b = 0b1100110000
# print(b ^ (b & (b - 1)))

# v = 0b1100110000

def msb(v):
    v |= v >> 1
    v |= v >> 2
    v |= v >> 4
    v |= v >> 8
    v |= v >> 16
    v += 1
    return v


assert msb(1) == 2
assert msb(3) == 4
assert msb(13) == 16
