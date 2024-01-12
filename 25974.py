import sys
input=sys.stdin.readline
MOD = 10**9+7
n,p=map(int,input().split())

def power(a,b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b % 2 == 0:
        return power(a,b//2)**2
    else:
        return power(a,b//2)**2 * a 

pascal = [[1]*(p+2) for _ in range(p+2)]
for i in range(1,p+2):
    for j in range(1,i):
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

dp = [0]*(p+1)
dp[0] = n
for i in range(1,p+1):
    dp[i] = power(n+1, i+1) - 1
    for j in range(0, i):
        dp[i] -= pascal[i+1][j] * dp[j]
    dp[i] //= (i+1)
print(dp[p] % MOD)