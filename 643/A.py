#
# ~oisín~ Python3 Template
#

import sys
import math
import statistics
import datetime
import collections

def computemax(n):
    ans = [n]
    while 1:
        mindig = 9
        maxdig = 0
        for c in str(ans[len(ans)-1]):
            mindig = min(mindig, int(c))
            maxdig = max(maxdig, int(c))
        if mindig*maxdig == 0:
            break
        temp = ans[len(ans)-1]
        temp += mindig*maxdig
        ans.append(temp)
    return ans

def main():
    t = int(input())
    for _ in range(t):
        a, k = map(int, input().split())
        temp = computemax(a)
        if(k-1 > len(temp)-1):
            print(temp[len(temp)-1])
        else:
            print(temp[k-1])


if __name__ == '__main__':
    main()
