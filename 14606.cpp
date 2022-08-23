#include <bits/stdc++.h>
using namespace std;

int dp[15]={0,0};
int n;
int f(int n) {
    if (n <= 1 || dp[n]) return dp[n];
    return dp[n]=f(n-n/2)+f(n/2)+((n/2)*(n-n/2));
}

int main(void) {
    cin >> n;
    cout << f(n) << endl;
    return 0;
}