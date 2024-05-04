n, m = map(int, input().split())

l = []
for i in range(n):
    l.append(int(input()))

def solution(l : list, m : int) -> int:
    l.sort()
    N = len(l)
    fidx, sidx = 0, 0
    ans = 2_000_000_000
    while fidx < N and sidx < N:
        if l[sidx] - l[fidx] == m:
            return m
        if l[sidx] - l[fidx] < m:
            sidx += 1
        else:
            ans = min(ans, l[sidx] - l[fidx])
            fidx += 1
    return ans

print(solution(l, m))