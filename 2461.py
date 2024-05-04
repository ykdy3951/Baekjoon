n, m = map(int,input().split())
l = []
for i in range(n):
    for j in list(map(int,input().split())):
        l.append([j, i])
l.sort()

N = n * m
fidx, sidx = 0, 0
cnt = 0
val = [0] * n
ans = 1000000005
while fidx < N and sidx < N:
    if val[l[sidx][1]] == 0:
        cnt+=1
    val[l[sidx][1]]+=1
    sidx+=1
    while cnt == n:
        ans = min(ans, l[sidx-1][0]-l[fidx][0])
        val[l[fidx][1]]-=1
        if val[l[fidx][1]] == 0:
            cnt -= 1
        fidx += 1
print(ans)