#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define INF 987654321
#define sc1(a) scanf("%c", &a)
#define ss1(a) scanf("%s", s)
#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d %d", &a, &b)
#define sd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define psd1(a) printf("%d ", a)
#define pnd1(a) printf("%d\n", a)
#define plld1(a) printf("%lld", a)
#define pslld1(a) printf("%lld ", a)
#define pnlld1(a) printf("%lld\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define vt vector
#define pr pair
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int n;
int res, maxleaf;
bool chk[10001];

vt<pr<int, int>> G[10001];

void init()
{
    sd1(n);
    f(i, 0, n - 1)
    {
        int a, b, c;
        sd3(a, b, c);
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
}

void dfs(int num, int weight)
{
    for (int i = 0; i < G[num].size(); i++)
    {
        if (chk[G[num][i].first])
            continue;

        int next = G[num][i].first;
        int tw = G[num][i].second;

        chk[next] = true;

        if (weight + tw > res)
        {
            res = weight + tw;
            maxleaf = next;
        }

        dfs(next, weight + tw);
    }
}

void solve()
{
    chk[1] = true;
    dfs(1, 0);

    memset(chk, false, n + 1);
    chk[maxleaf] = true;
    dfs(maxleaf, 0);

    pnd1(res);
}

int main(void)
{
    init();
    solve();
    return 0;
}