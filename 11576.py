a,b=map(int,input().split())
n=int(input())
l=list(map(int,input().split()))[::-1]
s=0
x=[]
y=1
for i in l:
    s+=y*i
    y*=a
while s:
    s,t=divmod(s,b)
    x.append(t)
print(*x[::-1])