import sys
input=sys.stdin.readline
n,f=map(int,input().split())
idx, time = 0, 20000.0
for i in range(n):
    x,v=map(int,input().split())
    time_x = (f-x)/v
    if time_x < time:
        idx = i+1
        time = time_x
print(idx)