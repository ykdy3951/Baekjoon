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

int n,m;
vt<pr<int, int>> v[101];
int dist[101];

void solve(int s, int e)
{
    fill_n(dist, n + 1, INF);

    priority_queue<pr<int, int>> pq;
    pq.push({0, s});
    dist[s]= 0;

    while(!pq.empty()) {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        if(now == e) 
            break;
        
        for(pr<int, int> pii : v[now]) {
            int next = pii.first, nw = pii.second + w;

            if(nw >= dist[next]) continue;

            dist[next] = nw;

            pq.push({-nw, next});
        }
    }

    pnd1(dist[e] == INF ? -1 : dist[e]);
}

void init()
{
    int a, s, e, w;
    sd2(n, m);

    while(m--) {
        sd1(a);

        if (a) {
            sd3(s, e, w);
            v[s].pb({e, w});
            v[e].pb({s, w});
        }
        else {
            sd2(s, e);
            solve(s, e);
        }
    }
}

int main(void)
{
    init();
    return 0;
}