from collections import deque
n,m,r=map(int,input().split())
g=[[] for _ in range(n+1)]
for _ in range(m):
    x,y=map(int,input().split())
    g[x].append(y)
    g[y].append(x)
for i in range(1,n+1):
    g[i].sort()
d=deque([r])
cnt = 1
chk=[0]*(n+1)
while d:
    a=d.popleft()
    chk[a]=cnt
    cnt += 1
    for i in g[a]:
        if not chk[i]:
            chk[i]=1
            d.append(i)
for i in range(1, n+1):
    print(chk[i])