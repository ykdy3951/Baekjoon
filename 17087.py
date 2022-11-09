def gcd(a, b):
    if a < b:
        a,b=b,a
    while a % b:
        a,b=b,a%b
        if a < b:
            a,b=b,a
    return b

global s

def f(n):
    n=int(n)
    return abs(s-n)

n,s=map(int,input().split())
l=list(map(f,input().split()))
while len(l) != 1:
    l.append(gcd(l.pop(),l.pop()))
print(l[0])        