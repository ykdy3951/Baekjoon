import sys
input=sys.stdin.readline

d=[[0]*1001 for _ in range(51)]

n,s,m=map(int,input().split())
l=list(map(int,input().split()))
ans = -1

def bt(now, cost):
    global ans
    if (now == n):
        ans = max(ans, cost)
        return
    if (d[now][cost]):
        return
    d[now][cost]=True
    if (cost - l[now] >= 0):
        bt(now + 1, cost - l[now])
    if (cost + l[now] <= m):
        bt(now + 1, cost + l[now])

bt(0, s)
print(ans)