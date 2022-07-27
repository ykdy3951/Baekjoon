a,b=map(int,input().split())
if a > b:
    a,b=b,a
x=a;y=b//2+b%2
print(y,x)