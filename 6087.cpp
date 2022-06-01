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

int w, h, ans;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

// an inaccessible direction
const int chk[] = {1, 0, 3, 2, -1};

char m[101][101];
vt<pr<int,int>> node;
// first member is the number of changing directions, 2nd member is direction and 3th & 4th member are coordinates
priority_queue<pr<int, pr<int, pr<int, int>>>> pq;
int cost[101][101];

void init()
{
    sd2(w, h);
    f(i, 0, h) {
        f(j, 0, w) {
            cost[i][j] = INF;
            
            char c;
            scanf(" %1c", &c);

            m[i][j]=c;
            if(c == 'C') {
                node.pb({i, j});
            }
        }
    }

    pq.push({1, {4, node[0]}});
    cost[node[0].first][node[0].second] = 0;
    m[node[0].first][node[0].second] = '.';
}

void solve()
{
    while(!pq.empty()) 
    {
        int c = -pq.top().first, direction = pq.top().second.first;
        pr<int, int> coord = pq.top().second.second;

        pq.pop();

        if(coord == node[1]) {
            ans = c;
            break;
        }

        f(i, 0, 4) {

            if(chk[direction] == i) continue;

            int nx = dx[i] + coord.first, ny = dy[i] + coord.second, nc = c;
            
            // 못가는 지역
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(m[nx][ny] == '*') continue;

            // 방향 바꾼 후 가려는 지역이 이미 낮은 cost로 지나갔을 경우 pass
            if(direction != i) nc++;
            if(nc > cost[nx][ny]) continue;
            
            cost[nx][ny] = nc;
            pq.push({-nc, {i, {nx, ny}}});
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