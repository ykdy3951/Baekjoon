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
int board[10][10];
bool row[10][10];
bool col[10][10];
bool mat[10][10];
vt<pr<int, int>> v;
bool flag = false;

void init()
{
    fe(i, 1, 9)
    {
        fe(j, 1, 9)
        {
            scanf(" %1d", &board[i][j]);
            if (board[i][j] == 0)
            {
                v.pb({i, j});
            }

            else
            {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                mat[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][board[i][j]] = true;
            }
        }
    }
    n = v.size();
}

void solve(int now)
{
    if (now == n)
    {
        flag = true;
        return;
    }

    int x = v[now].first, y = v[now].second;

    fe(i, 1, 9)
    {
        if (mat[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i])
            continue;
        if (row[x][i])
            continue;
        if (col[y][i])
            continue;

        mat[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = true;
        row[x][i] = true;
        col[y][i] = true;
        board[x][y] = i;
        solve(now + 1);

        if (flag)
        {
            return;
        }

        mat[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = false;
        row[x][i] = false;
        col[y][i] = false;
    }
}

int main(void)
{
    init();
    solve(0);

    fe(i, 1, 9)
    {
        fe(j, 1, 9)
        {
            pd1(board[i][j]);
        }
        printf("\n");
    }

    return 0;
}