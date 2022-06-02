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
#define sd5(a, b, c, d, e) scanf("%d %d %d %d %d", &a, &b, &c, &d, &e)
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

int n, m, a, b, c, ans = INF;
vt<pr<int,int>> v[11];
bool vst[11];

void init()
{
    sd5(n,m,a,b,c);

    f(i, 0, m) {
        int x, y, z;
        sd3(x, y, z);

        v[x].pb({y, z});
        v[y].pb({x, z});
    }
}

void solve(int now, int sum, int maxCost)
{
    if (sum > c) return;
    if (now == b) {
        ans = min(ans, maxCost);
        return;
    }

    for(pr<int, int> pii : v[now]) {
        if(vst[pii.first]) continue;

        vst[pii.first] = true;
        solve(pii.first, sum + pii.second, max(maxCost, pii.second));
        vst[pii.first] = false;
    }
}

int main(void)
{
    init();
    solve(a, 0, 0);
    pnd1(ans == INF ? -1 : ans);
    return 0;
}