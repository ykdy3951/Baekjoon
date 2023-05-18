INF=987654321
n=int(input());l=[]
for i in range(n-1):
    l.append(list(map(int,input().split())))
k=int(input())
dp=[[INF, INF] for _ in range(n)]
for i in range(3):
    dp.append([INF,INF])
dp[0]=[0,0]
for i in range(1,n):
    dp[i][0]=min(dp[i-1][0]+l[i-1][0], dp[i-2][0]+l[i-2][1])
    dp[i][1]=min(dp[i-1][1]+l[i-1][0], dp[i-2][1]+l[i-2][1], dp[i-3][0]+k)
print(min(dp[n-1]))