import sys
import math

t = int(input())

for _ in range(t):
    x, n, m = map(int, input().split())
    while n > 0:
        temp = (x//2)+10
        if temp < x:
            x = temp
            n -= 1
        else:
            break
    while m > 0:
        x -= 10
        m -= 1
    if x <= 0:
        print("YES")
    else:
        print("NO")
