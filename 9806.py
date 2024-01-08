import sys
input=sys.stdin.readline
n=int(input())
s=int(input())
a=list(map(lambda x: x ** s, filter(lambda x: x ** s > 0, list(map(int,input().split())))))
print(sum(a))