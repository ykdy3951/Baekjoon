import sys
input=sys.stdin.readline
MOD = 1000000007

n, k = map(int, input().split())

def pow(a, b):
    if b == 0:
        return 1
    elif b % 2:
        return (pow(a, b // 2) ** 2 * a) % MOD
    else:
        return (pow(a, b // 2) ** 2) % MOD
    
a = 1
b = 1

l = [1] * (n + 1)
for i in range(2, n + 1):
    l[i] = l[i - 1] * i % MOD

a = l[n]
b = l[k] * l[n - k] % MOD

print(((a % MOD) * (pow(b, MOD - 2))) % MOD)