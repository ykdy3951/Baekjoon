from math import *
n=int(input())
l=[0]*1003002

l[0]=l[1]=1

for i in range(2, int(sqrt(1003002))+1):
    if l[i]:
        continue
    for j in range(i*i, 1003002, i):
        l[j]=1

for i in range(n, 1003002):
    if l[i] == 0 and str(i) == str(i)[::-1]:
        print(i)
        break