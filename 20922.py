n, k = map(int, input().split())
l = list(map(int,input().split()))

from collections import defaultdict

def solution(l:list, n:int, k:int) -> int:
    d=defaultdict(int)
    fidx, sidx = 0, 0
    ans = 0
    temp = 0
    while fidx < n and sidx < n:
        if d[l[sidx]] < k:
            temp += 1
            d[l[sidx]]+=1
            sidx+=1
        else:
            ans = max(temp, ans)
            temp -=1
            d[l[fidx]]-=1
            fidx+=1

    return max(ans, temp)

print(solution(l, n, k))