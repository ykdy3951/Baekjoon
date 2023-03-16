import sys
input=sys.stdin.readline

n=int(input())
l=list(map(int,input().split()))
d=[987654321]*n

d[n-1]=0
for i in range(n-1,-1,-1):
    for j in range(i+1,min(i+l[i]+1,n)):
        d[i]=min(d[i],d[j]+1)
print(d[0] if d[0] != 987654321 else -1)