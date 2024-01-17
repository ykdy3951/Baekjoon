import sys
input=sys.stdin.readline
MOD = 10_000
def power(a,b):
    if b==0:
        return 1
    elif b==1:
        return a
    elif b%2==0:
        return power(a,b//2)**2%MOD
    else:
        return power(a,b//2)**2*a%MOD

def length(n):
    s = 9
    var_len = 2
    start = 1
    ans = 0
    while s <= n:
        ans = (ans + (s-start+1)*(var_len)) % MOD
        start *= 10
        s = s*10 + 9
        var_len += 1
    ans = (ans + (n-start+1)*(var_len)) % MOD
    return ans

n=int(input())
pow_2 = power(2,n-1)

print((length(n)*(pow_2+1)+2*(n-2)+(2*pow_2))%MOD)