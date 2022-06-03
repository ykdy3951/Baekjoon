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

int n;
vt<int> v[1001];
int dist[1001];
int data[1001];
int ans;

bool chk[1001];

priority_queue<pr<int, int>> pq;

void init()
{
    int m;
    sd1(n);

    fe(i, 1, n) {
        sd1(data[i]);
        sd1(m);
        while(m--) {
            int tmp;
            sd1(tmp);

            v[i].pb(tmp);
        }
    }

    fill_n(dist, n + 1, INF);
    dist[1] = 0;
    pq.push({0, 1});
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();        
        
        if(chk[now]) continue;
        chk[now] = true;
        ans = max(ans, w + data[now]);

        for(int i : v[now]) {
            int nw = data[now] + w;

            if(nw >= dist[i]) continue;

            dist[i] = nw;
            pq.push({-nw, i});
        }
    }
}

int main(void)
{
    init();
    solve();
    pnd1(ans);
    return 0;
}