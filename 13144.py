from collections import defaultdict

N = int(input())
l = list(map(int,input().split()))

def solution(l : list, N : int) -> int:

    ans = 0
    j = 0
    d = defaultdict(int)
    for i in range(N):
        while j < N and not d[l[j]]:
            d[l[j]] = 1
            j += 1

        ans += j - i
        d[l[i]] -= 1

    return ans

print(solution(l, N))