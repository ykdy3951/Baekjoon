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

int n, k, ans = INF;
vt<pr<int, int>> v[2501];
priority_queue<pr<int, pr<int, pr<int, int>>>> pq;
int dist[51][51];

void init()
{
    sd2(n, k);
    f(i, 0, n) {
        f(j, 0, n) {
            int a;
            sd1(a);
            v[a].pb({i, j});
            dist[i][j] = INF;
            if(a == 1) {
                pq.push({0, {1, {i, j}}});
            }
        }
    }
}

void solve()
{
    fe(i, 1, k) {
        if(v[i].size() == 0) {
            return;
        }
    }
    while(!pq.empty()) {
        int w = -pq.top().first, val = pq.top().second.first, x = pq.top().second.second.first, y = pq.top().second.second.second;
        pq.pop();

        if(val == k) {
            ans = w;
            return;
        }

        for (pr<int, int> pii : v[val + 1]) {
            int nw = w + abs(x - pii.first) + abs(y - pii.second);
            
            if(dist[pii.first][pii.second] <= nw) continue;
            dist[pii.first][pii.second] = nw;

            pq.push({-nw, {val + 1, {pii.first, pii.second}}});
        }
    }
}

int main(void)
{
    init();
    solve();
    pnd1(ans == INF ? -1 : ans);
    return 0;
}