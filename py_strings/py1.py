# -*- utf-8 -*-
a = 2 ** 10000
print(a)

b = 2.1241234
c = 1 + 2j
d = 3 - 3.2j
print(c * d)

myList = [2, 3, 10, 6, 15]
myList.sort()
print(*myList)
# ?????????? ? ???????? ???????
myList.sort(reverse=True)
print(*myList)


# myList.sort(cmp=myCompare)

# ??????? ? Python
def f(a, b):
    return a + b


# ?????? ???????
def emptyFunction():
    pass


# ?????????? ????? ????????
# Greatest Common Divider
def GCD(a, b):
    if b == 0:  # == - ????????? (=), != - ?? ????? (<>)
        # < > >= <=
        return a
    else:
        return GCD(b, a % b)  # % - mod


# ???????? ? Python
# + - * /
# "//"  - div - ????????????? ???????
# "%"  - mod - ??????? ?? ???????

if (a > 1) and (a < 10) or (a == 100) and (not b == 3):
    print("!!!")

if (True or False):
    print("True or False")

# function GCD(a, b : integer):integer;
# begin
# end;

b = [1]
print(*b)
b[0] = 2
print(*b)
b.append(10)
print(*b)
b[1] = 120
print(*b)

f = [1, 1]
N = 100
i = 2
while N > 0:
    f.append(f[i - 1] + f[i - 2])
    i += 1  # i = i + 1
    N -= 1
print(*f)
i = 0
for k, v in enumerate(f):
    print(k, v)

print("A%dB" % 20)  # A20B

array = [5, 9, 4, 100]
print(array)
print(list(enumerate(array)))
array2 = sorted(array)
print(array2)


# ?????????? ? ????????? ??????????
x = 10
y = 1


def f():
    global y
    y = 5
    print(x)


f()
print(y)