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

int n, m, k;
priority_queue<int> dist[1005];
vector<pair<int, int>> G[1005];

void init()
{
    sd3(n, m, k);
    f(i, 0, m)
    {
        int a, b, c;
        sd3(a, b, c);
        G[a].pb({b, c});
    }
}

void dijkstra()
{
    priority_queue<pr<int, int>, vt<pr<int, int>>, greater<pr<int, int>>> pq;
    dist[1].push(0);
    pq.push({0, 1});
    while (!pq.empty())
    {
        int w = pq.top().first, now = pq.top().second;
        pq.pop();
        for (int i = 0; i < G[now].size(); i++)
        {
            int next = G[now][i].first, dw = G[now][i].second;
            if (dist[next].size() < k || dist[next].top() > w + dw)
            {
                if (dist[next].size() == k)
                    dist[next].pop();
                dist[next].push(w + dw);
                pq.push({w + dw, next});
            }
        }
    }
}

int main(void)
{
    init();
    dijkstra();
    fe(i, 1, n)
    {
        if (dist[i].size() == k)
            pnd1(dist[i].top());
        else
            pnd1(-1);
    }
    return 0;
}