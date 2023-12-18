n,s=map(int,input().split());x=0
for i in range(n-1):
    x+=int(input())
    if x > s:
        x-=1
print(x+int(input()))