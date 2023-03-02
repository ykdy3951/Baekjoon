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

int v, e, p;
int dist[5001];
bool chk[5001];
vt<pii> G[5001];

int solve(int start, int end)
{
    fill_n(dist, v + 1, INF);
    fill_n(chk, v + 1, 0);
    priority_queue<pii> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        if (now == end) return dist[now];
        if (chk[now]) continue;
        chk[now] = true;

        for(pii t : G[now])
        {
            int nw = w + t.second;
            int next = t.first;

            if (chk[next] || nw >= dist[next]) continue;
            dist[next] = nw;

            pq.push({-nw, next});
        }
    }

    return dist[end];
}

void init()
{
    sd3(v, e, p);
    
    int a, b, c;
    f(i, 0, e)
    {
        sd3(a, b, c);
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int cost = solve(1, v);

    if (cost == solve(1, p) + solve(p, v))
        printf("SAVE HIM\n");
    else
        printf("GOOD BYE\n");
}

int main(void)
{
    init();
    return 0;
}