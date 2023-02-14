#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp1[1005], dp2[1005];

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);
    dp1[0]=dp2[n-1]=1;
    for(int i = 1; i < n; i++)
    {
        dp1[i]=dp2[n-1-i]=1;
        for(int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp1[i] = max(dp1[i], dp1[j]+1);
            if (arr[n-1-i] > arr[n-1-j])
                dp2[n-1-i] = max(dp2[n-1-i], dp2[n-1-j]+1);
        }
    }
    int ans=0;
    for(int i = 0; i < n; i++)
    {
        ans=max(ans, dp1[i]+dp2[i]-1);
    }
    printf("%d\n", ans);
    return 0;
}