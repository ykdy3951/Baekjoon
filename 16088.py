import sys
input=sys.stdin.readline
for _ in range(int(input())):
    a,b,x,y=map(int,input().split())
    if x == y:
        print('G')
        continue
    t = abs(x-y)
    if t <= a and t <= b:
        print('E')
    elif t <= a:
        print('L')
    else:
        print('R')