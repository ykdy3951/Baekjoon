import sys
input=sys.stdin.readline
n,m=map(int,input().split())
MOD=1000000007

def pow(a,b):
    if b==0:
        return 1
    elif b==1:
        return a
    elif b%2==0:
        return pow(a,b//2)**2%MOD
    else:
        return pow(a,b//2)**2*a%MOD

factorial=[1]*(n+1)
for i in range(2,n+1):
    factorial[i]=factorial[i-1]*i%MOD

print(factorial[n]*pow(factorial[m]*factorial[n-m],MOD-2)%MOD)