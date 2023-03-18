from math import *
n, t = map(int,input().split())
t *= 60 
m=int(input())
x, y = map(int,input().split())


print(max(0, ceil((m / x + (n- m) / y - t)/60)))