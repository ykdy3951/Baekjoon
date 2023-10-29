from collections import deque
r,c=map(int,input().split())
m=[[0 for _ in range(c)] for _ in range(r)]
l=[];f=[[0 for _ in range(c)] for _ in range(r)];jihun=[0,0];fire=[]
for i in range(r):
    l.append(list(input()))
for i in range(r):
    for j in range(c):
        if l[i][j] == "J":
            jihun=[i,j]
            f[i][j]=987654321
        elif l[i][j] == "F":
            fire.append([i, j])
        elif l[i][j] == "#":
            f[i][j] = -1
        else:
            f[i][j]=987654321 
d=deque([])
for i in fire:
    d.append([i, 0])
dx=[0,0,-1,1]
dy=[-1,1,0,0]
while d:
    now, w = d.popleft()
    x, y = now
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        if nx < 0 or nx >= r or ny < 0 or ny >= c or f[nx][ny] <= w + 1:
            continue
        f[nx][ny] = w + 1
        d.append([[nx, ny], w+1])
d=deque([[jihun, 0]])
while d:
    now, w = d.popleft()
    x, y = now
    if x in [0, r-1] or y in [0, c-1]:
        print(w+1)
        exit()
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        if w + 1 >= f[nx][ny] or l[nx][ny] == '#':
            continue
        l[nx][ny] = '#'
        d.append([[nx, ny], w+1])
print("IMPOSSIBLE")