import math
import sys

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    b = n - 2*(k - 1)
    if b % 2 == 0 and b > 0:
        print("YES")
        for i in range(0, k-1):
            print(2, end = ' ')
        print(b)
    else:
        b = n - (k - 1)
        if b % 2 == 1 and b > 0:
            print("YES")
            for i in range(0, k-1):
                print(1, end=' ' )
            print(b)
        else:
            print("NO")
