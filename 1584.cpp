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

int n, m;
int arr[501][501];
int dist[501][501];
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
priority_queue<pr<int, pr<int, int>>> pq;

void init()
{
    sd1(n);
    int x1, y1, x2, y2;
    
    while(n--) {
        sd4(x1, y1, x2, y2);

        fe(i, min(x1, x2), max(x1, x2)) {
            fe(j, min(y1, y2), max(y1, y2)) {
                arr[i][j] = 1;
            }
        }
    }

    sd1(m);

    while(m--) {
        sd4(x1, y1, x2, y2);

        fe(i, min(x1, x2), max(x1, x2)) {
            fe(j, min(y1, y2), max(y1, y2)) {
                arr[i][j] = 2;
            }
        }
    }

    fill(&dist[0][0], &dist[500][500]+4, INF);
    
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        if(x == 500 && y == 500) {
            
            return;
        }

        f(i, 0, 4) {
            int nx = dx[i] + x, ny = dy[i] + y, nw = w;

            if(nx < 0 || nx > 500 || ny < 0 || ny > 500) continue;

            if(arr[nx][ny] == 2) continue;
            if(arr[nx][ny]) nw++;

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
    pnd1(dist[500][500] == INF ? -1 : dist[500][500]);
    return 0;
}