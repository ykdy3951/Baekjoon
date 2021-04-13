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

int n, m;
int arr[100001];
ll dist[100001];
bool chk[100001];
priority_queue<pr<ll, int>, vt<pr<ll, int>>, greater<pr<ll, int>>> pq;
vt<vt<pr<int, ll>>> G;

void init()
{
    sd2(n, m);
    f(i, 0, n)
    {
        sd1(arr[i]);
        dist[i] = LONG_LONG_MAX;
    }
    G.resize(n + 1);
    f(i, 0, m)
    {
        int a, b;
        ll w;
        sd2(a, b);
        slld1(w);

        if ((a != n - 1 && arr[a]) || (b != n - 1 && arr[b]))
            continue;

        G[a].pb({b, w});
        G[b].pb({a, w});
    }
}

ll dijkstra()
{
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        ll w = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        chk[now] = true;

        if (now == n - 1)
        {
            return w;
        }

        if (dist[now] < w)
        {
            continue;
        }

        for (int i = 0; i < G[now].size(); i++)
        {
            int next = G[now][i].first;
            ll dw = G[now][i].second;

            if (chk[next])
                continue;
            if (dist[next] <= w + dw)
                continue;

            dist[next] = w + dw;
            pq.push({w + dw, next});
        }
    }

    return -1;
}

int main(void)
{
    init();
    ll ans = dijkstra();
    pnlld1(ans);
    return 0;
}