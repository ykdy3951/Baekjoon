from math import *
n,k = map(int,input().split())
l=[0]*(n+1)

l[0]=l[1]=1

cnt = 0
for i in range(2, n+1):
    if l[i]:
        continue
    cnt +=1
    if cnt == k:
        print(i)
        exit(0)
    for j in range(i*i, n+1, i):
        if l[j]:
            continue
        l[j]=1
        cnt += 1
        if cnt == k:
            print(j)
            exit(0)