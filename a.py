import sys

while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break

    incomes = [int(x) for x in sys.stdin.readline().rstrip().split()]
    ave = sum(incomes) / len(incomes)

    print(sum([x <= ave for x in incomes]))
