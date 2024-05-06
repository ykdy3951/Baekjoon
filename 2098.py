n = int(input())
w = [list(map(int, input().split())) for _ in range(n)]

dp = [[0] * (1 << n) for _ in range(n)]
MAX = 1e10
TOTAL = (1 << n) - 1

def tsp(curr, visited):
    if visited == TOTAL:
        if w[curr][0] == 0:
            return MAX
        else:
            return w[curr][0]
    
    if dp[curr][visited] != 0:
        return dp[curr][visited]
    
    dp[curr][visited] = MAX
    for i in range(1, n):
        if not visited & (1 << i) and w[curr][i] != 0:
            dp[curr][visited] = min(dp[curr][visited], tsp(i, visited | (1 << i)) + w[curr][i])
    return dp[curr][visited]

print(tsp(0, 1))