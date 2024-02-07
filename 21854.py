import sys
input=sys.stdin.readline
MOD = 10**9+7

n = int(input())
l = list(map(int, input().split()))

ans = 0
for i in l:
    ans += pow(2, i, MOD)
    ans %= MOD
print(ans)