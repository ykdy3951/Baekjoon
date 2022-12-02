input()
l=list(map(int,input().split()))
d={}
n=int(input())
for i in l:
    d[n%i]=i
print(d[min(d.keys())])