l=[list(map(int,input().split())) for _ in range(5)]
r,c=map(int,input().split())
ans=0
dx=[-1,1,0,0]
dy=[0,0,-1,1]

def bt(x, y, w, cnt):
    if cnt < 0:
        return
    if l[x][y] < 0:
        return
    t = l[x][y]
    l[x][y] = -1
    global ans
    ans=max(ans, w)
    for i in range(4):
        nx,ny=x+dx[i],y+dy[i]
        if nx < 0 or nx >=5 or ny < 0 or ny >= 5:
            continue
        if l[nx][ny] == -1:
            continue
        bt(nx, ny, w + l[nx][ny], cnt - 1)
    l[x][y] = t

bt(r, c, max(l[r][c], 0), 3)
print(1 if ans >= 2 else 0)