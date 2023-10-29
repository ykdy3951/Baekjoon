n=int(input())
l=list(map(int,input().split()))+[0]
dp=[0] * n
c=0
ans=[0]*n
for i in range(n+1):
    if l[i] < 0:
        c+=1
    else:
        if c > 0:
            dp[i-c] = c
            c=0
m=max(dp)
ll=[]
for i in range(n):
    if dp[i] == m:
        ll.append(i)
    if dp[i] > 0:
        for j in range(max(i-dp[i]*2, 0), i):
            ans[j]=1
cnt=0
for i in ll:
    for j in range(max(i-dp[i]*3,0), i-dp[i]*2):
        if ans[j] != 1:
            c+=1
    cnt = max(cnt, c)
    c=0
print(sum(ans)+cnt)