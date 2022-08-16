#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int arr[2][16];
string ans;
string a, b;

void dp(int cnt) {
    if (cnt == 3) {
        ans=to_string((arr[1][0]+arr[1][1])%10)+to_string((arr[1][1]+arr[1][2])%10);
        return;
    }
    for(int i = 0; i < cnt - 1; i++) {
        arr[(cnt+1)%2][i]=(arr[cnt%2][i]+arr[cnt%2][i+1])%10;
    }
    dp(cnt-1);
}

void change() {
    for(int i = 0; i < 8; i++) {
        arr[0][i*2] = a[i]-'0';
        arr[0][i*2+1] = b[i]-'0';
    }
}

int main(void) {
    
    cin >> a >> b;
    
    change();
    dp(16);
    cout << ans << endl;
    return 0;
}