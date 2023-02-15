#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1000005];

int solve(int val)
{
    if (dp[val] != -1) return dp[val];
    
    dp[val]=987654321;
    
    for(int i = 1; i <= val/2; i++)
    {
        if (val-i <= 0) continue;
        dp[val] = min(dp[val], solve(val-i)+solve(i));    
    }
    
    return dp[val];
}

int main(void)
{
    scanf("%d %d", &n, &k);
    memset(dp, -1, (k+1)*sizeof(int));
    int t;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        dp[t]=1;
    }
    int ans=solve(k);
    if (ans > 10000)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}