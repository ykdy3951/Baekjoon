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

int n, a, b;
vector<vector<int>> v;
priority_queue<pr<int,int>> pq;
int dist[105];

void init()
{
    sd3(n,a,b);
    a--;b--;
    f(i, 0, n) {
        int s;
        sd1(s);
        vector<int> t;
        f(j, 0, s) {
            int c;
            sd1(c);
            t.pb(c-1);
        }
        v.pb(t);
    }

    fill_n(dist, n, INF);
    pq.push({0, a});
    dist[a]=0;
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        if (now == b) {
            pnd1(w);
            break;
        }

        for(int i = 0; i < v[now].size(); i++) {
            int nw = w + min(i, 1);
            int next = v[now][i];
            if(dist[next] <= nw) continue;
            
            dist[next] = nw;
            pq.push({-nw, next});
        }
    }

    if (dist[b] == INF) {
        pnd1(-1);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}