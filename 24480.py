import sys
sys.setrecursionlimit(10**5)
n,m,r=map(int,input().split())
cnt=1
g=[[] for _ in range(n+1)]
for _ in range(m):
    x,y=map(int,input().split())
    g[x].append(y)
    g[y].append(x)

cnt = 1
chk=[0]*(n+1)
chk[r]=1
def dfs(x):
    global cnt
    g[x].sort(reverse=True)
    for i in g[x]:
        if not chk[i]:
            cnt+=1
            chk[i]=cnt
            dfs(i)

dfs(r)
for i in range(1, n+1):
    print(chk[i])
