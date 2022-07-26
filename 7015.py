a=5*39;b=10*20
t=333*b+666*a+1
for _ in range(int(input())):
    y,m,d=map(int,input().split())
    l=(y-1)//3
    n=y-1-l
    q=l*b+n*a
    if y % 3:
        q+=d+(m-1)//2*39+((m-1)%2)*20
    else:
        q+=20*(m-1)+d
    print(t-q)
