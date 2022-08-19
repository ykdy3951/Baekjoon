#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[50][2];
int n;

int main(void) {

    cin >> n;
    
    arr[0][0]=1;arr[0][1]=0;
    
    for(int i = 1; i <= n; i++) {
        arr[i][0]=arr[i-1][1];
        arr[i][1]=arr[i-1][0]+arr[i-1][1];
    }
    
    cout << arr[n][0] << " " << arr[n][1] << endl;
    
    return 0;
}