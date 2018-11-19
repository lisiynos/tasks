# -*- coding: utf-8 -*-

# Поиск самой правой единички в битовом представлении числа
def right(v):
    return (v ^ (v & (v - 1)))


assert right(0b11001100) == 0b100


# Поиск самой левой единички в битовом представлении числа

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
assert msb(0b1100110000) == 0b10000000000
