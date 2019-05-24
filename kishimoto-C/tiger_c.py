def mymax(num):
    max_num = 1
    start_num = num
    for i in range(1, int(num / 2 + 2)):
        if num % i == 0:
            # 偶数個の場合
            if (((i + 1) / 2) - (num / i) > 0):
                if ((((i + 1) / 2) - (num / i)) % 1 == 0):
                    return (num / i) * 2, ((i + 1) / 2) - (num / i), 1
            # 奇数個の場合
            if (i - (((num / i) - 1) / 2) > 0):
                if (max_num < num / i):
                    if ((i - (((num / i) - 1) / 2)) % 1 == 0):
                        start_num = i - (((num / i) - 1) / 2)
                        max_num = num / i
        if (max_num > (num / i) * 2): return max_num, start_num, 2
    # 二個の場合
    if (max_num == 1):
        if ((num - 1) % 2 == 0):
            max_num = 2
            start_num = (num - 1) / 2
    return max_num, start_num, 3

while (True):
    num = int(input())
    if (num == 0): break
    max_num, start_num, status = mymax(num)
    if int(start_num) == 0:
        start_num = 1
        max_num -= 1
    print("{} {}".format(int(start_num), int(max_num)))