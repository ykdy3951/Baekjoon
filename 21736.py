from collections import deque
n,m=map(int,input().split())
l=[list(input()) for _ in range(n)]
chk=[[0]*m for _ in range(n)]
dx,dy=[-1,1,0,0],[0,0,-1,1]
s=[0,0]
for i in range(n):
    for j in range(m):
        if l[i][j] == 'I':
            s=[i,j]
            chk[i][j]=1
d=deque([s])
c=0
while d:
    x,y=d.popleft()
    if l[x][y] == 'P':
        c+=1
    for i in range(4):
        nx,ny=x+dx[i],y+dy[i]
        if nx < 0 or nx >= n or ny <0 or ny >= m or l[nx][ny] == 'X' or chk[nx][ny]:
            continue
        chk[nx][ny]=1
        d.append([nx,ny])
print(c if c else 'TT')