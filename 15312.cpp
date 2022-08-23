#include <bits/stdc++.h>

using namespace std;

int dp[2][5000],n;
const int c[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
string a,b;
string ans;

void f(int n, int idx) {
    if (n == 2) {
        ans=to_string(dp[1-idx][0])+to_string(dp[1-idx][1]);
        return;
    }
    
    for(int i = 0; i < n-1; i++) {
        dp[idx][i]=(dp[1-idx][i]+dp[1-idx][i+1])%10;
    }
    
    f(n-1,1-idx);
}

int main(void) {

    cin >> a >> b;
    n=a.length();
    for(int i = 0; i < n; i++) {
        dp[0][i*2]=c[a[i]-'A'];
        dp[0][i*2+1]=c[b[i]-'A'];
    }
    
    f(2*n,1);
    cout << ans << endl;
    
    return 0;
}