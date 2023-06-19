from collections import deque
n,m,r=map(int,input().split())
g=[[] for _ in range(n+1)]
for _ in range(m):
    x,y=map(int,input().split())
    g[x].append(y)
    g[y].append(x)
d=deque([r])
cnt = 1
chk=[0]*(n+1)
chk[r]=1
while d:
    a=d.popleft()
    g[a].sort(reverse=True)
    for i in g[a]:
        if not chk[i]:
            cnt += 1
            chk[i]=cnt
            d.append(i)
for i in range(1, n+1):
    print(chk[i])