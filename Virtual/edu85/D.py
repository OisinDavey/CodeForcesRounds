import math
import sys

A = 1
B = 1
C = 1 
K = 0

def LFromI(I):
    return I*I*A + I*B + C

def IFromL(L):
    return math.floor((-B+math.sqrt(B*B - 4*A*(C-L)))/(2*A))

def Out(l, R):
    curint = IFromL(l)
    curpos = LFromI(curint)

    while curpos <= R:
        if curint == K:
            print(1, end=' ')
            break
        for i in range(2*(K-curint)):
            if curpos+i > R:
                break
            if curpos+i < l:
                continue
            if i % 2 == 0:
                print(curint, end=' ')
            else:
                print(curint + (i+1)//2, end=' ' )
        curint += 1
        curpos = LFromI(curint)
    return 1;

t = int(input())

for _ in range(t):
    K, l, r = map(int, input().split())

    A = -1
    B = 2*K+1
    C = -2*K

    Out(l-1, r-1)
    print()
