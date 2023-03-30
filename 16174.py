n=int(input())
m=[list(map(int,input().split())) for i in range(n)]
c=[[0]*n for _ in range(n)]
q = []
q.append([0,0])
c[0][0]=1
while len(q):
    t = q.pop(0)
    x=m[t[0]][t[1]]
    if x + t[0] < n and c[t[0]+x][t[1]]==0:
        c[t[0]+x][t[1]]=1
        q.append([t[0]+x, t[1]])
    if x + t[1] < n and c[t[0]][t[1]+x]==0:
        c[t[0]][t[1]+x]=1
        q.append([t[0], t[1]+x])
    if (x + t[0] == n-1 and t[1] == n-1) or (t[0] == n-1 and x+t[1] == n-1):
        print('HaruHaru')
        exit(0)
print('Hing')