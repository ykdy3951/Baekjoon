import sys
input=sys.stdin.readline

MOD = 1000000007

n, r = map(int, input().split())

factorial = [1] * (n+1)
for i in range(2, n+1):
    factorial[i] = factorial[i-1] * i % MOD

def power(a, b):
    if b == 0:
        return 1
    elif b % 2:
        return power(a, b-1) * a % MOD
    else:
        return power(a, b//2) ** 2 % MOD

print((factorial[n] * power(factorial[r] * factorial[n-r] % MOD, MOD-2)) % MOD)