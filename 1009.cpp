#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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
#define f(i, a, b) for (i = a; i < b; i++)

int n;
vector<pair<int, int>> v;
vector<int> Data[11] = {
    {10},
    {1},
    {6, 2, 4, 8},
    {1, 3, 9, 7},
    {6, 4},
    {5},
    {6},
    {1, 7, 9, 3},
    {6, 8, 4, 2},
    {1, 9},
};

void init()
{
    sd1(n);
    int i;
    f(i, 0, n)
    {
        int a, b;
        sd2(a, b);
        v.push_back({a, b});
    }
}

void solve()
{
    int i;
    f(i, 0, n)
    {
        int a = v[i].first, b = v[i].second;
        a = a % 10;
        b = b % Data[a].size();
        pnd1(Data[a][b]);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}