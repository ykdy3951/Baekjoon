n,m=map(int,input().split())
l=list(map(int,input().split()))

def solution(l : list, m : int) -> int:
    N = len(l)
    fidx, sidx = 0, 0
    part_sum = l[0]
    ans = 0
    while fidx < N and sidx < N:
        if part_sum == m:
            ans += 1
            part_sum -= l[fidx]
            fidx += 1
            sidx += 1
            if sidx != N:
                part_sum += l[sidx]
        elif part_sum > m:
            part_sum -= l[fidx]
            fidx += 1
        else:
            sidx += 1
            if sidx != N:
                part_sum += l[sidx]

    return ans

print(solution(l, m))