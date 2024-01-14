import sys
input=sys.stdin.readline
n,m,k=map(int,input().split())
print(max(0,n-m*k), n-m*(k-1)-1)