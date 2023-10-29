t,w=map(int,input().split())

l=[]
ans = 0
started = 1
treeNum = 1
treeCnt = 0
for _ in range(t):
    x=int(input())
    if started:
        if x == treeNum:
            ans += 1
        else:
            started = 0
            treeNum = x
            treeCnt = 1
    elif x == treeNum:
        treeCnt += 1
    else:
        l.append(treeCnt)
        treeNum = x
        treeCnt = 1
if treeCnt > 0:
    l.append(treeCnt)
l=[ans]+l
ans = 0
memo = [[-1 for _ in range(w + 1)] for _ in range(len(l))] 

def solve(idx, cnt):
    if cnt < 0:
        return -987654321
    if idx >= len(l):
        return 0
    if memo[idx][cnt] != -1:
        return memo[idx][cnt]
    
    memo[idx][cnt] = l[idx] + max(solve(idx+2, cnt), solve(idx+1, cnt-1))
    return memo[idx][cnt]

print(solve(0, w))
