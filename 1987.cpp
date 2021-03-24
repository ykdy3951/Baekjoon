#include <bits/stdc++.h>

using namespace std;

#define fio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define pr pair
#define pb push_back
#define f(i, a, b) for (i = a; i < b; i++)

int r, c;
bool chk[26];
int arr[21][21];
int res;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init()
{
    sd2(r, c);
    int i, j;
    f(i, 1, r + 1)
    {
        f(j, 1, c + 1)
        {
            char ch;
            scanf(" %1c", &ch);
            arr[i][j] = ch - 'A';
        }
    }
    chk[arr[1][1]] = true;
}

void solve(int cnt, int x, int y)
{
    if (res < cnt)
    {
        res = cnt;
    }
    int i;
    f(i, 0, 4)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || nx > r || ny <= 0 || ny > c)
            continue;
        if (chk[arr[nx][ny]])
            continue;
        chk[arr[nx][ny]] = true;
        solve(cnt + 1, nx, ny);
        chk[arr[nx][ny]] = false;
    }
}

int main(void)
{
    init();
    solve(1, 1, 1);
    pnd1(res);
    return 0;
}