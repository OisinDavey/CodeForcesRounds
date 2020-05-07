import math
import sys

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    if(a+c == b and b == d):
        print("Yes")
    elif(a+d == b and b == c):
        print("Yes")
    elif(b+c == a and a == d):
        print("Yes")
    elif(b+d == a and a == c):
        print("Yes")
    else:
        print("No")
