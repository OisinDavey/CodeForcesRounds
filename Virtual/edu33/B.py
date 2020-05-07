import sys
import math

BeauNums = []

bas = "1"

for i in range(0, 10):
    BeauNums.append(int(bas, 2))
    bas = "1" + bas + "0"

n = int(input())

for i in range(9, -1, -1):
    if n % BeauNums[i] == 0:
        print(BeauNums[i])
        exit()
