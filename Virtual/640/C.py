import math
import sys

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    print((k-1)%(n-1)+1+n*((k-1)//(n-1)))
