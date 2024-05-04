n = int(input())
l = list(map(int,input().split()))

def solution(l:list, n:int) -> int:
    arr = []

    for i in range(n-1):
        for j in range(i+1, n):
            arr.append([l[i]+l[j], i, j])
    
    arr.sort()

    fidx, sidx = 0, 0
    ans = 2000000000
    N = (n - 1) * n // 2
    for i in range(N-1):
        j = i+1
        while j < N and (arr[i][1] in arr[j][1:] or arr[i][2] in arr[j][1:]):
            j += 1
        if j == N:
            break
        ans = min(ans, arr[j][0] - arr[i][0])
    return ans

print(solution(l, n))