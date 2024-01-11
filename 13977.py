import sys
input=sys.stdin.readline

MOD = 1000000007

factorial = [1 for _ in range(4000001)]
for i in range(2, 4000001):
    factorial[i] = (factorial[i - 1] * i) % MOD

def power(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a
    elif b % 2 == 0:
        return power((a * a) % MOD, b // 2)
    else:
        return (a * power((a * a) % MOD, b // 2)) % MOD
    
for _ in range(int(input())):
    n, k = map(int, input().split())
    print((factorial[n] * power(factorial[k] * factorial[n - k], MOD - 2)) % MOD)