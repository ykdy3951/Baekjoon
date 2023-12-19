import sys
input=sys.stdin.readline
n,k=map(int,input().split());x=0;ans=0
for i in range(n):
    a,b=map(int,input().split())
    x+=a-b
    ans=max(ans,x-k)
print(ans)