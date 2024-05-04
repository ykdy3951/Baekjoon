from collections import defaultdict

n, d, k, c = map(int,input().split())
l = []
for i in range(n):
    l.append(int(input()))

l = l + l[:k]

def solution(l:list, k:int, c:int) -> int:
    d = defaultdict(int)

    fidx, sidx = 0, 0
    ans = 0
    temp = 1
    size = 1
    d[l[0]] += 1
    N = len(l)
    while fidx < N and sidx < N:
        if size == k:
            if not d[c]:
                ans = max(ans, temp + 1)
            else:
                ans = max(ans, temp)

            d[l[fidx]] -= 1
            if not d[l[fidx]]:
                temp -= 1
            fidx += 1
            size -= 1
        else:
            sidx += 1
            if sidx != N:
                if not d[l[sidx]]:
                    temp += 1
                d[l[sidx]] += 1
            size += 1

    return max(ans, temp)

print(solution(l, k, c))
            