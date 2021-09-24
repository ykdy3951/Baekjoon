#include <bits/stdc++.h>
using namespace std;
int n;
void solve(int i, int j, int n) {
    if (i / n % 3 == 1 && j / n % 3 == 1) {
        printf(" ");
    }
    else if (n / 3 == 0) {
        printf("*");
    }
    else {
        solve(i, j, n / 3);
    }
}
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            solve(i, j, n);
        printf("\n");
    }
    return 0;
}