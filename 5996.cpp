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
#define pii pair<int,int>
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int t, c, s, e;
priority_queue<pii> pq;
vt<vt<pii>> G;
int dist[2505];

void solve()
{
    pq.push({0, s});
    fill_n(dist, t+1, INF);
    dist[s]=0;

    while(!pq.empty())
    {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        if (now == e)
        {
            break;
        }

        for(pii next : G[now])
        {
            if (dist[next.first] <= w + next.second) continue;
            dist[next.first] = w + next.second;

            pq.push({-(w+next.second), next.first});
        }
    }

    pnd1(dist[e]);
}

void init()
{
    sd4(t,c,s,e);
    G.resize(t+1);
    int x, y, z;
    f(i,0,c)
    {
        sd3(x, y, z);
        G[x].pb({y, z});
        G[y].pb({x, z});
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}