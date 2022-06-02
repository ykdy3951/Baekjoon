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

int n, m, x;
vt<pr<int, int>> v[1001];
priority_queue<pr<int, int>> pq;
int dist[1001];

void init()
{
    sd3(n,m,x);
    while(m--) {
        int a, b, c;
        sd3(a, b, c);
        v[a].pb({b, c});
        v[b].pb({a, c});
    }

    fill_n(dist, n + 1, INF);
    dist[0] = 0;
    dist[x] = 0;
    pq.push({0, x});
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        for(pr<int, int> pii : v[now]) {
            int next = pii.first, nw = pii.second + w;

            if(nw >= dist[next]) continue;
            dist[next] = nw;

            pq.push({-nw, next});
        }
    }
}

int main(void)
{
    init();
    solve();
    pnd1(*max_element(dist, dist + n + 1) * 2);
    return 0;
}