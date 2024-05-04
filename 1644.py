N = int(input())
from math import sqrt, ceil
def solution(N : int) -> int:
    if N == 1:
        return 0
    chk_prime = [0] * (N+1)
    chk_prime[0] = chk_prime[1] = 1
    for i in range(2, ceil(sqrt(N))+1):
        if chk_prime[i]:
            continue
        for j in range(i*i, N+1, i):
            chk_prime[j] = 1
    
    prime_list = []
    for i in range(N+1):
        if not chk_prime[i]:
            prime_list.append(i)

    LEN = len(prime_list)
    fidx, sidx = 0, 0
    ans = 0
    part_sum = prime_list[0]
    while fidx < LEN and sidx < LEN:
        if part_sum == N:
            ans += 1
            part_sum -= prime_list[fidx]
            fidx += 1
            sidx += 1
            if sidx != LEN:
                part_sum += prime_list[sidx]
        elif part_sum > N:
            part_sum -= prime_list[fidx]
            fidx += 1
        else:
            sidx += 1
            if sidx != LEN:
                part_sum += prime_list[sidx]
    return ans

print(solution(N))