#include <bits/stdc++.h>

using namespace std;

int dp[1001] = {0, 1, 2};
int n;
string ans[2] = {"CY", "SK"};

int main(void) {

    cin >> n;

    for(int i = 3; i <= n; i++) {
        dp[i]=min(dp[i-1]+1,dp[i-3]+1);
    }
    
    cout << ans[dp[n]%2] << endl;
    
    return 0;
}