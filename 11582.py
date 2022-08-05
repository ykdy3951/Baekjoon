n=int(input());a=n;s=2
l=list(map(int,input().split()))
k=int(input())
while(a != k):
    t=[]
    for i in range(0,n,s):
        t+=sorted(l[i:i+s])
    l=list(t)
    a//=2
    s*=2
print(*l)