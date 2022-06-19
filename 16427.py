n,s=map(int,input().split())
l=list(map(int,input().split()))
a,b=divmod(max(l)*s,1000)
print(a+min(1,b))