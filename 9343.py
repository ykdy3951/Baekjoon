import sys
input=sys.stdin.readline
MOD=1_000_000_007

def pow(a,b):
    if b==0:
        return 1
    if b%2:
        return pow(a,b-1)*a%MOD
    else:
        return pow(a,b//2)**2%MOD

fact=[1]*2_000_001

for i in range(2,1_000_001):
    fact[i]=fact[i-1]*i%MOD

for _ in range(int(input())):
    n=int(input())
    print(fact[2*n]*pow(fact[n] * fact[n+1] % MOD,MOD-2)%MOD)
