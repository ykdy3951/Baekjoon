n,x=map(int,input().split())
l=list(map(int,input().split()))
m=0;t=1
for i in range(1,n):
    if l[i]-l[i-1] <= x:
        t+=1
    else:
        m=max(m,t)
        t=1
print(max(m,t))