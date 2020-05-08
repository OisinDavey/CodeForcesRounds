import math
import sys

w1, h1, w2, h2 = map(int, input().split())

if w2 > w1:
    temp = w1
    w1 = w2
    w2 = temp

print(4 + 2*w1 + 2*(h1+h2))
