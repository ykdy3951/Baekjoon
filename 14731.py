import sys
input=sys.stdin.readline
MOD = 10**9+7

ans = 0
for i in range(int(input())):
    c, k = map(int, input().split())
    ans += pow(2, k - 1, MOD) * c * k
    ans %= MOD
print(ans)