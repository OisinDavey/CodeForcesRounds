import math
import sys

def HFromC(c):
    return math.floor((-0.5+math.sqrt(0.25+6*c))/3)

def CFromH(h):
    return int(1.5*h*h + 0.5*h)

t = int(input())

for _ in range(t):
    c = int(input())
    h = 0
    it = 0
    while(c >= 2):
        c -= CFromH(HFromC(c))
        it += 1
    print(it)

