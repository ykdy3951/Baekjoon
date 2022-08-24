#include <iostream>
using namespace std;

#define ll long long
#define MOD 1000000007

int t;
int c, v, l;
ll arr[20][2];

ll dp(int n, int flag) {
    if (arr[n][flag]) return arr[n][flag];
    return arr[n][flag]=((1-flag)*((dp(n-1,1)*c)%MOD)+(dp(n-1,0)*v)%MOD)%MOD;
}

int main(void) {
    
    cin >> t;
    for(int tc=1; tc<=t; tc++) {
        cin >> c >> v >> l;
	for(int i = 1; i <= l; i++) {
  	    arr[i][0]=arr[i][1]=0;
	}
        arr[1][0]=(c+v)%MOD;
        arr[1][1]=c%MOD;
    
        cout << "Case #" << tc << ": " << dp(l,1) << endl;
    }
    return 0;
}
