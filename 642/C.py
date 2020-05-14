#
# ~oisín~ Python3 Template
#

import sys
import math
import statistics
import datetime
import collections

def main():
    ans = [0, 0, 0]
    for i in range(3, 500001):
        if i%2 == 0:
            ans.append(0)
        else:
            ans.append(2*i*i-4*i+2+ans[i-2])
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(ans[n])

if __name__ == '__main__':
    main()
