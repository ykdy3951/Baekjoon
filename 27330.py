n=int(input())
l=list(map(int,input().split()))
m=int(input())
x=list(map(int,input().split()))

a=0
for i in range(n):
    a+=l[i]
    if a in x:
        a=0
print(a)