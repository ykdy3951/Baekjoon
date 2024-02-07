import sys
input=sys.stdin.readline

MOD=1_000_000_007

def power(a,b):
    if b==0:
        return 1
    elif b==1:
        return a
    elif b%2==0:
        return power(a,b//2)**2%MOD
    else:
        return power(a,b//2)**2*a%MOD
    
ans = 0
for _ in range(int(input())):
    n,s=map(int,input().split())
    ans += (s * power(n, MOD-2)) % MOD
print(ans % MOD)