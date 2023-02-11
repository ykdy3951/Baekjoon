#include <bits/stdc++.h>
using namespace std;

int ans, n;

void func(int s, int e)
{
    if (s+1 == e)
    {
        ans+=s*e;
        return;
    }

    if (s == e)
    {
        return;
    }

    func(s, s-1+(e-s+2)/2);
    func(s+(e-s+2)/2, e);
    return;
}

int main(void)
{
    scanf("%d", &n);
    func(1,n);
    printf("%d\n", ans);
}