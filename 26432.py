import sys
input=sys.stdin.readline

t=int(input())

for tc in range(t):
    m, n, p = map(int,input().split())

    l=[[]*m for _ in range(n)]

    for _ in range(m):
        x=list(map(int,input().split()))
        for i in range(n):
            l[i].append(x[i])
    ans = 0

    for i in range(n):
        ans += max(l[i]) - l[i][p-1]

    print(f'Case #{tc+1}: {ans}')
