import math
import sys

t = int(input())

for _ in range(t):
    a = input()
    s = []
    for i in range(len(a)):
        if(a[i]!='0'):
            ans = a[i]
            for j in range(i+1, len(a)):
                ans += "0"
            s.append(ans)
    print(len(s))
    for x in s:
        print(x, end=' ')
    print()
