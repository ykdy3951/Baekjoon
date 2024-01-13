import sys
input=sys.stdin.readline
r,c=map(int,input().split())
arr=[list(map(int,list(input().rstrip()))) for _ in range(r)]

LUarr = [[0]*(c+2) for _ in range(r+2)]
RUarr = [[0]*(c+2) for _ in range(r+2)]
LDarr = [[0]*(c+2) for _ in range(r+2)]
RDarr = [[0]*(c+2) for _ in range(r+2)]

for i in range(r):
    for j in range(c):
        if arr[i][j]==1:
            LUarr[i+1][j+1]=LUarr[i][j]+1
            RUarr[i+1][j+1]=RUarr[i][j+2]+1

for i in range(r-1,-1,-1):
    for j in range(c):
        if arr[i][j]==1:
            LDarr[i+1][j+1]=LDarr[i+2][j]+1
            RDarr[i+1][j+1]=RDarr[i+2][j+2]+1

ans = 0
for i in range(1,r+1):
    for j in range(1,c+1):
        for k in range(min(LDarr[i][j],RDarr[i][j]),0,-1):
            if ans >= k:
                break
            if i+2*(k-1) <= r and arr[i+2*(k-1)-1][j-1] and LUarr[i+2*(k-1)][j]>=k and RUarr[i+2*(k-1)][j]>=k:
                ans = max(ans,k)
                break
        for k in range(min(RUarr[i][j],RDarr[i][j]),0,-1):
            if ans >= k:
                break
            if j+2*(k-1) <= c and arr[i-1][j+2*(k-1)-1] and LUarr[i][j+2*(k-1)]>=k and LDarr[i][j+2*(k-1)]>=k:
                ans = max(ans,k)
                break
        
print(ans)