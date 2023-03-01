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

int n, l, r;
int arr[51][51];
bool chk[51][51];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int c;
int s;

vector<pr<int, int>> v;

void solve(int x, int y)
{
    v.push_back({x, y});
    chk[x][y] = true;
    c+=1;
    s+=arr[x][y];
    f(i, 0, 4)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (chk[nx][ny]) continue;
        if (abs(arr[x][y] - arr[nx][ny]) >= l && abs(arr[x][y] - arr[nx][ny]) <= r)
        {
            solve(nx, ny);
        }
    }
}

void init()
{
    sd3(n, l, r);
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            sd1(arr[i][j]);
        }
    }

    int ans = 0;

    while(1)
    {   
        int f = 0;
        memset(chk, 0, sizeof(chk));
        f(i, 0, n)
        {
            f(j, 0, n)
            {
                c=0, s=0, v.clear();
                if (!chk[i][j])
                {
                    solve(i, j);
                    if (v.size() == 1) f++;

                    f(i, 0, c)
                    {
                        arr[v[i].first][v[i].second] = s/c;
                    }
                }
            }
        }
        if (f == n * n)
            break;
        else
            ans++;
    }

    pnd1(ans);
}

int main(void)
{
    init();
    return 0;
}