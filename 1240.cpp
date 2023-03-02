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

int n, m;
vt<vt<pii>> G;

int dist[1005];
bool chk[1005];

void solve(int start, int end)
{
    fill_n(dist, n+1, INF);
    memset(chk, 0, sizeof(chk));

    priority_queue<pii> q;
    q.push({0, start});
    while(!q.empty())
    {
        int w = -q.top().first, now = q.top().second;
        q.pop();
        if (now == end) return;
        if (chk[now]) continue;
        chk[now] = true;

        for(pii next : G[now])
        {
            if (chk[next.first]) continue;
            if (dist[next.first] <= w + next.second) continue;

            dist[next.first] = w + next.second;
            q.push({-(w+next.second), next.first});
        }
    }
}

void init()
{
    sd2(n, m);
    G.resize(n+1);
    int a, b, w;
    f(i, 0, n-1)
    {
        sd3(a, b, w);
        G[a].pb({b,w});
        G[b].pb({a,w});
    }

    while(m--)
    {
        sd2(a, b);
        solve(a, b);

        pnd1(dist[b]);
    }
}

int main(void)
{
    init();
    return 0;
}