n=int(input());cnt=0
dp = [[[0 for _ in range(n)] for __ in range(n)] for ___ in range(3)]
l=[]
for _ in range(n):
    l.append(list(map(int, input().split())))

dp[0][0][1] = 1
for i in range(2, n):
    if l[0][i] == 1:
        break
    dp[0][0][i] = dp[0][0][i - 1]

for i in range(1, n):
    for j in range(1, n):
        if l[i][j] == 0 and l[i][j-1] == 0 and l[i-1][j] == 0:
            dp[1][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1]
        if l[i][j] == 0:
            dp[0][i][j] = dp[0][i][j-1] + dp[1][i][j-1]
            dp[2][i][j] = dp[2][i-1][j] + dp[1][i-1][j]

print(dp[0][n-1][n-1]+dp[1][n-1][n-1]+dp[2][n-1][n-1])