from collections import deque
n,m=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(n)]
c=[[0]*m for _ in range(n)]
s=[0,0]
for i in range(n):
    for j in range(m):
        if l[i][j] == 2:
            s=[i,j]
        if l[i][j] % 2:
            c[i][j] = -1
d=deque([s+[0]])
dx=[-1,1,0,0]
dy=[0,0,-1,1]
while d:
    x,y,w=d.popleft()
    for i in range(4):
        nx,ny=x+dx[i],y+dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        nw = w+1
        if c[nx][ny] != -1:
            continue
        c[nx][ny]=nw
        d.append([nx,ny,nw])
for i in c:
    print(*i)