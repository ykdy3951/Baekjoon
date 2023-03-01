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

int n, m;
int arr[55][55];
bool chk[55][55];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vt<pii> v;

int ans;

int solve(int x, int y)
{
    int t = 0;
    queue<pr<int, pii>> q;
    q.push({0, {x, y}});
    chk[x][y] = 1;
    while(!q.empty())
    {
        int w = q.front().first;
        pii now = q.front().second;
        q.pop();
        t = max(t, w);

        for(int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (arr[nx][ny] == 0 || chk[nx][ny]) continue;

            chk[nx][ny] = true;
            q.push({w + 1, {nx, ny}});
        }
    }

    return t;
}

void init()
{
    sd2(n, m);
    char c;
    fe(i, 1, n)
    {
        fe(j, 1, m)
        {
            scanf(" %1c", &c);
            if (c == 'W')
                arr[i][j] = 0;
            else
            {
                v.pb({i, j});
                arr[i][j] = 1;
            }
        }
    }

    for(pii a : v)
    {
        memset(chk, 0, sizeof(chk));
        ans = max(ans, solve(a.first, a.second));
    }

    pnd1(ans);
}

int main(void)
{
    init();
    return 0;
}