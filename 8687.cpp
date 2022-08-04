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
const int dx[] = {-1, 1, 0}, dy[] = {0, 0, 1};
int arr[1005][1005];
int dist[1005][1005];
priority_queue<pr<int, pr<int, int>>> pq;
bool flag;

void init()
{
    sd2(n,m);
    f(i, 0, n) {
        f(j, 0, m) {
            sd1(arr[i][j]);
            dist[i][j] = INF;
        }
    }

    f(i, 0, n) {
        if(arr[i][0] == 0) {
            dist[i][0] = 0;
            pq.push({0, {i, 0}});
        }
    }
}

void solve()
{
    while(!pq.empty()) {
        int w = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        if (y == m-1) {
            flag=true;
            pnd1(w);
            break;
        }

        f(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i], nw = w + abs(dx[i]);

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (arr[nx][ny]) continue;
            if (dist[nx][ny] <= nw) continue;
            
            dist[nx][ny] = nw;
            pq.push({-nw, {nx, ny}});
        }
    }

    if(!flag) {
        printf("NIE\n");
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}