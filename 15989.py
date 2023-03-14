import sys
input=sys.stdin.readline

dp=[[0]*10001 for _ in range(3)]

dp[0][1]=dp[0][2]=dp[1][2]=dp[2][3]=1
dp[0][3]=2
for i in range(4, 10001):
    dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1]
    dp[1][i]=dp[1][i-2]+dp[2][i-2]
    dp[2][i]=dp[2][i-3]

for i in range(int(input())):
    n=int(input())
    print(dp[0][n]+dp[1][n]+dp[2][n])