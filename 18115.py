import sys
input=sys.stdin.readline
from collections import deque
n=int(input())
l=list(map(int,input().split()))[::-1]
index=1
hand=deque()
for i in l:
    if i == 1:
        hand.appendleft(index)
    elif i == 2:
        tmp = hand.popleft()
        hand.appendleft(index)
        hand.appendleft(tmp)
    else:
        hand.append(index)
    index+=1

print(*hand)