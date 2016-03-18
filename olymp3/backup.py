# ~*~ coding: utf-8 ~*~
import sys

ID = "backup"
sys.stdin = open(ID + ".in")
sys.stdout = open(ID + ".out", "w")

# Считваем входную строку
s = input()

# Словарь: символ -> сколько таких символов в строке уже было
cnt = {}
# Результирующая строка
res = []
# Пробегаем по символам строки
for c in s:
    # Если символ c в строке уже был
    if c in cnt:
        # Надо сделать резерную копию
        # Строка для backup'а
        backup = []
        while True:
            # Получаем последний символ
            last = res[-1]
            if last == c:
                # Переворачивам backup и выводим
                print("".join(backup[::-1]))
                break
            else:
                # Добавляем его к backup'у
                backup.append(res.pop())
                # Уменьшаем счётчик
                cnt[last] -= 1
                if cnt[last] == 0:
                    del cnt[last]
        cnt[c] += 1
    else:
        cnt[c] = 1
    # Добавляем новый символ
    res.append(c)

# Выводим остаток строки
print("".join(res))
