n=input()
if len(n) == 1:
    print(n)
else:
    a,b=n[0],len(n)-1
    n=int(n);a=int(a)
    b=10**b
    x=a*b
    y=(a+1)*b
    if (y - n <= n - x):
        print(y)
    else:
        print(x)