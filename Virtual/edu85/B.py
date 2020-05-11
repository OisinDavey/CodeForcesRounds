import math
import sys

t = int(input())

for _ in range(t):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort(reverse = True)
    s = 0
    ans = N
    for i in range(0, N):
        s += A[i]
        if s < (K * (i+1)):
            ans = i
            break
    print(ans)
