from math import sqrt

n = int(input())
l = [list(map(int, input().split())) for _ in range(n)]

w = [[0] * n for _ in range(n)]

for i in range(n-1):
    for j in range(i+1, n):
        w[i][j] = w[j][i] = sqrt((l[j][0] - l[i][0]) ** 2 + (l[j][1] - l[i][1]) ** 2) 

dp = [[0] * (1 << n) for _ in range(n)]
TOTAL = (1 << n) - 1
MAX = 1e10

def tsp(start, curr, visited):
    if visited == TOTAL:
        if w[curr][start] != 0:
            return w[curr][start]
        return MAX
    
    if dp[curr][visited] != 0:
        return dp[curr][visited]
    
    dp[curr][visited] = MAX
    for i in range(n):
        if not visited & (1 << i) and w[curr][i] != 0:
            dp[curr][visited] = min(dp[curr][visited], w[curr][i] + tsp(start, i, visited | (1 << i)))
    return dp[curr][visited]

print(tsp(0, 0, 1))