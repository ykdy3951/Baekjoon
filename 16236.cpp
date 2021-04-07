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

struct node
{
    int len, i, j;

    bool operator<(const node &n) const
    {
        if (len == n.len)
        {
            if (i == n.i)
            {
                return j > n.j;
            }
            else
            {
                return i > n.i;
            }
        }
        else
        {
            return len > n.len;
        }
    }
};

int arr[21][21];
bool chk[21][21];
priority_queue<node> pq;
int n, ans, sharksize = 2, eat;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void init()
{
    sd1(n);
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            sd1(arr[i][j]);
            if (arr[i][j] == 9)
            {
                pq.push({0, i, j});
                arr[i][j] = 0;
            }
        }
    }
}

void solve()
{
    while (!pq.empty())
    {
        int x = pq.top().i, y = pq.top().j, len = pq.top().len;
        pq.pop();

        if (0 < arr[x][y] && arr[x][y] < sharksize)
        {
            arr[x][y] = 0;
            eat++;
            if (eat == sharksize)
            {
                sharksize++;
                eat = 0;
            }
            ans += len;
            len = 0;
            memset(chk, false, sizeof(chk));
            while (!pq.empty())
                pq.pop();
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (0 > nx || nx >= n || 0 > ny || ny >= n)
                continue;
            if (chk[nx][ny])
                continue;
            if (0 < arr[nx][ny] && arr[nx][ny] > sharksize)
                continue;
            pq.push({len + 1, nx, ny});
            chk[nx][ny] = true;
        }
    }

    pnd1(ans);
}

int main(void)
{
    init();
    solve();
    return 0;
}