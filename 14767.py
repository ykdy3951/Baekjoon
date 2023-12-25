import sys
input=sys.stdin.readline
n,m=map(int,input().split());l=[]
for _ in range(n):
    l.append(list(map(int,input().split())))

a=[0]*n
for i in range(m):
    a[0]+=l[0][i]
    for j in range(1, n):
        a[j]=max(a[j-1], a[j])+l[j][i]

print(*a)