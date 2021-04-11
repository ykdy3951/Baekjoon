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

typedef vt<vt<ll>> mat;
const ll mod = 1000000007LL;

ll n;

mat operator*(const mat &a, const mat &b)
{
    int n = a.size();
    mat c(n, vt<ll>(n));
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            f(k, 0, n)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

void init()
{
    slld1(n);
}

void solve()
{
    if (n <= 1)
    {
        pnlld1(n);
        return;
    }

    mat ans = {{1, 0}, {0, 1}};
    mat a = {{1, 1}, {1, 0}};

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    pnlld1(ans[0][1]);
}

int main(void)
{
    init();
    solve();
    return 0;
}