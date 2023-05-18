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

bool chk[51][51];
int arr[51][51];

int w, h;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void search(int x, int y)
{
    queue<pii> q;
    q.push({x, y});

    while(!q.empty())
    {
        pii now = q.front();
        q.pop();

        int x = now.first, y = now.second;
        if(chk[x][y]) continue;

        chk[x][y] = true;

        f(i, 0, 8)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (chk[nx][ny]) continue;
            q.push({nx, ny});
        }
    }
}

void solve()
{
    int ans = 0;
    
    f(i, 0, h)
    {
        f(j, 0, w)
        {
            if (!chk[i][j])
            {
                search(i, j);
                ans++;
            }
        }
    }
    pnd1(ans);
}

void init()
{
    while(true) 
    {
        sd2(w, h);
        if (!(w + h)) break;

        f(i, 0, h)
        {
            f(j, 0, w)
            {
                chk[i][j] = false;
                sd1(arr[i][j]);
                if (!arr[i][j]) chk[i][j] = true;
            }
        }

        solve();
    }
}

int main(void)
{
    init();
    return 0;
}