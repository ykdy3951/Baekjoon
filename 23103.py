s=0;n=int(input());x,y=map(int,input().split())
for _ in range(n-1):
    i,j=map(int,input().split())
    s+=abs(x-i)+abs(y-j)
    x,y=i,j
print(s)