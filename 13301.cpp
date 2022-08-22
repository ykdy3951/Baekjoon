#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1000] = {0, 1, 1, 2, 3};
int n;

ll f(int n) {
    if (n==0 || dp[n]) return dp[n];
    return dp[n]=f(n-1)+f(n-2);
}

int main(void) {
    cin >> n;
    
    cout << 2*(2*f(n)+f(n-1)) << endl;
    return 0;
}