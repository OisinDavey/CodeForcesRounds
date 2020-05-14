#
# ~oisín~ Python3 Template
#

import sys
import math
import statistics
import datetime
import collections

def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        if n > 2:
            print(2*m)
        elif n == 2:
            print(m)
        else:
            print(0)
if __name__ == '__main__':
    main()
