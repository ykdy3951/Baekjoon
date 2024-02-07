import sys
input=sys.stdin.readline

n=int(input())
isPrime=[True]*(n+1)
isPrime[0]=isPrime[1]=False
mul_prime = []
for i in range(2, n+1):
    if isPrime[i]:
        mul_prime.append(i)
    j = i * i
    while j <= n:
        isPrime[j] = False
        j += i
ans = 1
for i in mul_prime:
    tmp = 1
    while (tmp * j) <= n:
        tmp *= i
    ans *= tmp

if n == 1:
    print('! 1')
else:
    print('?', ans - 1)
    sys.stdout.flush()
    print('!',int(input()) + 1)