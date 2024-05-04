n, k = map(int, input().split())
l = list(map(int, input().split()))

def solution(l:list, n:int, k:int) -> int:
    ans = 0
    temp = 0
    while temp < n and l[temp] % 2:
        temp += 1
    
    fidx, sidx = temp, temp
    temp = 0
    while fidx < n and sidx < n:
        if l[sidx] % 2 == 0:
            temp += 1
            sidx += 1
        else:
            if k == 0:
                ans = max(ans, temp)
                temp -= (1 - l[fidx] % 2)
                k += (l[fidx] % 2)
                fidx += 1
            else:
                k -= 1
                sidx += 1
    return max(ans, temp)

print(solution(l, n, k))