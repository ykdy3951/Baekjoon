#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define INF 987654321
#define sc1(a) scanf("%c", &a)
#define ss1(a) scanf("%s", s)
#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d %d", &a, &b)
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define pnd1(a) printf("%d\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define pr pair
#define pb push_back
#define f(i, a, b) for (i = a; i < b; i++)

int n;
vector<pr<int, int>> v;

int arr[30][30];

int comb(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else if (!arr[n][r])
    {
        return arr[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
    }
    return arr[n][r];
}

void init()
{
    sd1(n);
    int i;
    f(i, 0, n)
    {
        int a, b;
        sd2(a, b);
        v.pb({a, b});
    }
}

void solve()
{
    int i;
    f(i, 0, n)
    {
        pnd1(comb(v[i].second, v[i].first));
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}