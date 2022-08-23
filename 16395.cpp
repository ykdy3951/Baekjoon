#include <iostream>
#define ll long long
using namespace std;
int n, k;
ll dp[35][35]={{1},{1,1}};

ll f(int n, int k) {
    if(dp[n][k]) return dp[n][k];
    return dp[n][k]=f(n-1,k)+f(n-1,k-1);
}

int main(void) {
    cin >> n >> k;
    for(int i = 2; i < n; i++) {
        dp[i][0]=dp[i][i]=1;
    }
    cout << f(n-1,k-1) << endl;
    return 0;
}