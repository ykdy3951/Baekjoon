#include <bits/stdc++.h>
using namespace std;
int dp[11];
int a,b;

int f(int n) {
    if (n < 0) return 0;
    if (dp[n]) return dp[n];
    
    return dp[n]=max(max(f(n-1)*105/100,f(n-3)*120/100),f(n-5)*135/100);
}

int main() {
    cin >> a >> b;
    dp[0]=a;
    cout << f(b) << endl;
    return 0;
}