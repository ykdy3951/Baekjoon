import sys
input=sys.stdin.readline

n, p = map(int, input().split())
l = [*map(int, input().split())]
coefficients = [0] * p

for i in range(n, 0, -1):
    coefficients[i % (p-1)] += l[n-i]
    coefficients[i % (p-1)] %= p

print(l[n] % p)
coefficients[0] += l[n] % p

for i in range(1, p):
    ans = 0
    tmp = 1
    for j in range(p):
        ans += coefficients[j] * tmp
        tmp = (tmp * i) % p
    print(ans % p)