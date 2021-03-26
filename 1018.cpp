#include <bits/stdc++.h>

using namespace std;

#define fio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define INF 987654321
#define sc1(a) scanf(" %1c", &a)
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
#define f(i, a, b) for (i = a; i < b; i++)

int n, m;
int arr[51][51];

void init()
{
    sd2(n, m);

    int i, j;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            char ch;
            sc1(ch);

            if (ch == 'W')
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 1;
            }
        }
    }
}

void solve()
{
    int res = INF;
    int i, j, k, w;
    f(k, 0, n + 1 - 8)
    {
        f(w, 0, m + 1 - 8)
        {
            int cnt = 0;
            int val = arr[k][w];
            f(i, k, k + 8)
            {
                f(j, w, w + 8)
                {
                    if ((i + j) % 2)
                    {
                        if (arr[i][j] == val)
                        {
                            cnt++;
                        }
                    }
                    else
                    {
                        if (arr[i][j] == !val)
                        {
                            cnt++;
                        }
                    }
                }
            }
            cnt = min(cnt, 64 - cnt);
            res = min(res, cnt);
        }
    }
    pnd1(res);
}

int main(void)
{
    init();
    solve();
    return 0;
}