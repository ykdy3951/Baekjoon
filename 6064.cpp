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

int t;

void solve(int a, int b, int x, int y)
{
    vector<bool> chk(a + 1, false);

    int cnt = 0;

    while (y != 1)
    {
        x--;
        y--;
        cnt++;

        if (x == 0)
        {
            x += a;
        }
        if (y == 0)
        {
            y += b;
        }
    }

    int rks = b - a;
    int tmp;
    for (int i = 0;; i++)
    {
        tmp = rks * i;
        tmp %= a;
        if (chk[tmp])
        {
            break;
        }
        chk[tmp] = true;
        if (tmp == x - 1)
        {
            pnd1(i * b + cnt + 1);
            return;
        }
    }

    pnd1(-1);
}

void init()
{
    sd1(t);
    while (t--)
    {
        int a, b, x, y;
        sd4(a, b, x, y);

        if (a > b)
        {
            int tmp = a;
            a = b;
            b = tmp;

            tmp = x;
            x = y;
            y = tmp;
        }

        solve(a, b, x, y);
    }
}

int main(void)
{
    init();
    return 0;
}