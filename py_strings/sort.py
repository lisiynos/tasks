# -*- utf-8 -*-

# ??????????? ?? ????? ?????????? ??????? ??????
import os

ComputerName = os.getenv('COMPUTERNAME')
DEBUG = ComputerName == "DSTEPULE-RU"

# Assign(Input, 'sort.in'); Reset(Input);
# Assign(Output, 'sort.out'); Rewrite(Output);
import sys

sys.stdin = open("sort.in", "r")
if not DEBUG:
    sys.stdout = open("sort.out", "w")

# ????? ??????? ?? ???????? ?????
s = input()  # "2 5 6 4 -3"  # input()
if DEBUG: print(s)
a = s.split()  # "2 5 6" => [2,5,6]
if DEBUG: print(a)
# ???????? ????? ????? ?? ??????? ????????
# ??????? a
b = list(map(int, a))
bs = sorted(b)
print(*bs)