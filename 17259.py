b,n,m = map(int,input().split())

l=[]
for i in range(n):
    l.append(list(map(int,input().split()))+[0])

dx=[1,0,-1]
dy=[0,1,0]
x=[[0]*b for _ in range(b)]
c=0
for i in range(b*3-2+m):
    for j in range(b-1):
        x[b-1][j]=x[b-1][j+1]
    for j in range(b-2, -1, -1):
        x[j+1][b-1]=x[j][b-1]
    for j in range(b-2, -1, -1):
        x[0][j+1]=x[0][j]
    x[0][0]=0
    if i < m:
        x[0][0]=1

    for j in range(n):
        if l[j][3] != 0:
            l[j][3]=(l[j][3]+1)%l[j][2]
            continue
        for k in range(3):
            nx,ny=l[j][0]+dx[k],l[j][1]+dy[k]
            if x[nx][ny]:
                x[nx][ny]-=1
                l[j][3]=1
                c+=1
                break
print(c)