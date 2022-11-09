def f(n):
    i=2
    a=0
    while n // i:
        a+=n//i
        i*=2
    return a

def f2(n):
    i=5
    a=0
    while n // i:
        a+=n//i
        i*=5
    return a

a,b=map(int,input().split())
c=a-b
x=f(a)-f(b)-f(c);y=f2(a)-f2(b)-f2(c)
print(min(x,y))