for i in range(int(input())):
    x,y,a,b=map(int,input().split())
    if x > y:
        x,y=y,x
        a,b=b,a
    print(-1 if (y-x)%(a+b) else (y-x)//(a+b))