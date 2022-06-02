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
int arr[2225][2225];
int dist[2225][2225];
const int dx[] = {1, 0}, dy[] = {0, 1};
priority_queue<pr<int, pr<int, int>>> pq;

void init()
{
    sd1(n);

    f(i, 0, n) {
        f(j, 0, n) {
            sd1(arr[i][j]);
        }
    }

    f(i,0,n) {
        fill_n(dist[i], n, INF);
    }

    dist[0][0] = 0;
    pq.push({0, {0, 0}});
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        if(x == n-1 && y == n-1) {
            pnd1(w);
            return;
        }

        f(i, 0, 2) {
            int nx = x + dx[i], ny = y + dy[i];

            if(nx >= n || ny >= n) continue;

            int nw = w;
            if(arr[nx][ny] >= arr[x][y]) nw += arr[nx][ny] - arr[x][y] + 1;

            if(nw >= dist[nx][ny]) continue;

            dist[nx][ny] = nw;

            pq.push({-nw, {nx, ny}});            
        }
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}