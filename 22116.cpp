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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n;

ll arr[1005][1005];
ll dist[1005][1005];

void solve()
{
    priority_queue<pr<ll,pii>> pq;

    pq.push({0, {0, 0}});
    dist[0][0]=0;
    while(!pq.empty())
    {
        ll w = -pq.top().first;
        pii now = pq.top().second;
        pq.pop();

        if (now == make_pair(n-1, n-1))
        {
            break;
        }

        f(i, 0, 4)
        {
            pii next = {now.first + dx[i], now.second + dy[i]};
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) continue;
            ll nw = max(w, abs(arr[now.first][now.second]-arr[next.first][next.second]));

            if (nw >= dist[next.first][next.second]) continue;
            dist[next.first][next.second]=nw;
            pq.push({-nw, next});
        }
    }
    pnlld1(dist[n-1][n-1]);
}

void init()
{
    sd1(n);
    f(i,0,n)
    {
        f(j,0,n)
        {
            slld1(arr[i][j]);
            dist[i][j] = 9876543210;
        }
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}