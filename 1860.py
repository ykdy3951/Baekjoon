n, m = map(int, input().split())
l = list(map(int, input().split()))

def solution(l : list, m : int) -> int:
    MAX = 100005
    ans = MAX

    N = len(l)
    fidx, sidx = 0, 0
    part_sum = l[0]

    while fidx < N and sidx < N:
        if part_sum < m:
            sidx += 1
            if sidx < N:
                part_sum += l[sidx]
        else:
            ans = min(ans, sidx - fidx + 1)
            part_sum -= l[fidx]
            fidx += 1

    if ans == MAX:
        return 0
    return ans

print(solution(l, m))