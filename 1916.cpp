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

int n, m, s, e;
vt<pr<int, int>> G[1001];
bool chk[1001];
int dist[1001];
priority_queue<pr<int, int>, vt<pr<int, int>>, greater<pr<int, int>>> pq;

void init()
{
    sd2(n, m);
    f(i, 0, m)
    {
        int a, b, w;
        sd3(a, b, w);

        G[a].pb({b, w});
    }

    fe(i, 1, n)
    {
        dist[i] = 1e9;
    }
    sd2(s, e);
}

void dijkstra()
{
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        int w = pq.top().first, now = pq.top().second;
        pq.pop();

        if (now == e)
        {
            pnd1(w);
            return;
        }

        for (int i = 0; i < G[now].size(); i++)
        {
            int nxt = G[now][i].first, dw = G[now][i].second;
            if (chk[nxt])
                continue;

            if (dist[nxt] <= dist[now] + dw)
                continue;

            dist[nxt] = w + dw;
            pq.push({w + dw, nxt});
        }
    }
}

int main(void)
{
    init();
    dijkstra();
    return 0;
}