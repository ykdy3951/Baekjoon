#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t;
void print(ll x)
{
    if (x == 0) return;
    print(x/3);
    printf("%lld", x%3);
}
int main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        print(n);
        printf("\n");
    }
    return 0;
}