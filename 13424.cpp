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

int dist[101][101], ans[101];
int t,n,m;
vt<pr<int,int>> v[101];
vt<int> f;

void dijkstra(int s)
{
    bool chk[101];

    fill_n(chk, n + 1, false);
    priority_queue<pr<int, int>> pq;
    pq.push({0, s});
    dist[s][s] = 0;

    while(!pq.empty()) {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();
        if (chk[now] == true) {
            continue;
        }

        chk[now] = true;
        ans[now] += w;

        for(pr<int, int> pii : v[now]) {
            int next = pii.first, nw = pii.second + w;

            if (chk[next]) continue;
            if (nw >= dist[s][next]) continue;

            dist[s][next] = nw;
            pq.push({-nw, next});
        }
    }

}

void solve()
{
    sd1(t);
    while(t--) {
        int a, b, c, k;
        sd2(n,m);
        fe(i, 1, n) {
            fill_n(dist[i], n+1, INF);
            v[i].clear();
        }
        fill_n(ans, n+1, 0);
        while(m--) {
            sd3(a,b,c);
            v[a].pb({b,c});
            v[b].pb({a,c});
        }

        sd1(k);
        f(i, 0,k) {
            int node;
            sd1(node);
            dijkstra(node);
        }

        int index, mini = INF;

        fe(i, 1, n) {
            if(ans[i] < mini) {
                index= i;
                mini = ans[i];
            }
        }

        pnd1(index);
    }
}



int main(void)
{
    solve();
    return 0;
}