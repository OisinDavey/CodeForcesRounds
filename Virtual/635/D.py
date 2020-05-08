import math
import sys

def F(a, b, c):
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c)

t = int(input())

maxx = 10000000000000000000000000

for _ in range(t):
    R, G, B = map(int, input().split())
    
    r = list(map(int, input().split()))
    g = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    r.sort()
    g.sort()
    b.sort()
    
    x = 0
    y = 0
    z = 0

    ans = maxx 

    while x<(R-1) or y<(G-1) or z<(B-1):
        ans = min(ans, F(r[x], g[y], b[z]))

        d1 = maxx
        d2 = maxx
        d3 = maxx

        if x < (R-1):
            d1 = F(r[x+1], g[y], b[z])
        if y < (G-1):
            d2 = F(r[x], g[y+1], b[z])
        if z < (B-1):
            d3 = F(r[x], g[y], b[z+1])

        if d1<=d2 and d1<=d3:
            x += 1
        elif d2<=d1 and d2<=d3:
            y += 1
        else:
            z += 1

    ans = min(ans, F(r[x], g[y], b[z]))

    print(ans)
