from math import ceil
v,n=map(int,input().split())
for i in range(1,10):
    print(ceil(v*n*i/10),end=' ')