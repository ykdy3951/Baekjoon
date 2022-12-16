import sys
input=sys.stdin.readline
n,m=map(int,input().split())
l=[0]+list(map(int,input().split()))+[0]
c=0
for i in range(1,n+1):
    if l[i] == l[i-1]:
        continue
    if l[i]:
        c+=1
for _ in range(m):
    x=input()
    if x[0] == '0':
        print(c)
    else:
        a,b=map(int,x.split())
        if l[b] == 0:
            c+=-(l[b-1]+l[b+1])+1
            l[b]=1-l[b]