import sys
from math import ceil
input=sys.stdin.readline
a,b,c=map(int,input().split())
for i in range(1,int(ceil(a/b))):
    if (a-b*i) % c == 0:
        print(1)
        exit()
print(0)