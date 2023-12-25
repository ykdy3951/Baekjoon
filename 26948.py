import sys
input=sys.stdin.readline
n=int(input())
a=[0]*25
a[1]=1;a[2]=2;a[3]=4
for i in range(4,n+1):
    a[i]=a[i-1]+a[i-2]+a[i-3]
print(a[n])