import math

'''
b 予算
k 総数、大きくしたい
n 何階から買うか
'''


def calcKmax(b):
    Kmax = (1 + (1 + math.sqrt(b) * 8)) / 2
    return Kmax


while True:
    b = int(input())
    if b == 0:  # 終了条件
        break
    k = int(calcKmax(b))
    # print('kmax =',k)
    for i in range(k, 0, -1):
        if (i != 0) and (2 * b % i == 0) and (((2 * b / i) + 1 - i) % 2 == 0):
            n = int((2 * b / i + 1 - i) / 2)
            if (n > 0):
                print(n, i)
                break
