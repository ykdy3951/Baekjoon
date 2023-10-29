dp=[1, 1, 3]+[0]*248

for i in range(3, 251):
    dp[i] = dp[i-1] + 2*dp[i-2]
l =list(open(0))
for i in l:
    print(dp[int(i)])