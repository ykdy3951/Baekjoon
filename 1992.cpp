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
int arr[65][65];

void init()
{
    sd1(n);
    fe(i, 1, n)
    {
        fe(j, 1, n)
        {
            scanf(" %1d", &arr[i][j]);
        }
    }
}

void solve(int si, int sj, int sizei, int sizej)
{
    int zo = arr[si][sj];
    bool flag = true;
    f(i, si, si + sizei)
    {
        f(j, sj, sj + sizej)
        {
            if (arr[i][j] != zo)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        pd1(zo);
        return;
    }
    sizei /= 2;
    sizej /= 2;
    printf("(");
    solve(si, sj, sizei, sizej);
    solve(si, sj + sizej, sizei, sizej);
    solve(si + sizei, sj, sizei, sizej);
    solve(si + sizei, sj + sizej, sizei, sizej);
    printf(")");
}

int main(void)
{
    init();
    solve(1, 1, n, n);
    return 0;
}