#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[1000005];
int l[1000005];
int r[1000005];
int n;

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a=arr[0], b=arr[n-1];
    for(int i = 0; i < n; i++) {
        a=max(a,arr[i]);
        l[i]=a;
        b=max(b,arr[n-1-i]);
        r[n-1-i]=b;
    }
    for(int i = 0; i < n; i++) {
        printf("%d %d\n",l[i],r[i]);
    }
    return 0;
}