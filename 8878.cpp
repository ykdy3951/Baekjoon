#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>

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

// (a+b*x')*((((1-p)/p)**b-1)/((1-p)/p)**a+b-1)-b*x'

double x, p;
double arr[80005];

double pow_c(int n) 
{
    if (n == 0) return arr[0] = 1;
    if (arr[n] != 0) {
        return arr[n];
    }
    return arr[n] = pow_c(n-1) * (1-p) / p;
}

double func(int a, int b) {
    return (a+b*(1-x))*((pow_c(b)-1)/(pow_c(a+b)-1))-b*(1-x);
}

void solve()
{
    int start_a = 0, end_a = 40000;

    while (end_a - start_a >= 3)
    {
        int mid1 = (2 * start_a + end_a) / 3;
        int mid2 = (start_a + 2 * end_a) / 3;

        int start_b = 0, end_b = 40000;
        while (end_b - start_b >= 3)
        {
            int mid3 = (2 * start_b + end_b) / 3;
            int mid4 = (start_b + 2 * end_b) / 3;

            if (func(mid1, mid3) < func(mid1, mid4))
            {
                start_b = mid3;
            }
            else
            {
                end_b = mid4;
            }
        }

        double max_for_mid1 = max(func(mid1, start_b), max(func(mid1, start_b+1), func(mid1, start_b+2)));

        start_b = 0, end_b = 40000;
        while (end_b - start_b >= 3)
        {
            int mid3 = (2 * start_b + end_b) / 3;
            int mid4 = (start_b + 2 * end_b) / 3;

            if (func(mid2, mid3) < func(mid2, mid4))
            {
                start_b = mid3;
            }
            else
            {
                end_b = mid4;
            }
        }

        double max_for_mid2 = max(func(mid2, start_b), max(func(mid2, start_b+1), func(mid2, start_b+2)));

        if (max_for_mid1 < max_for_mid2)
        {
            start_a = mid1;
        }
        else
        {
            end_a = mid2;
        }
    }

    double max_for_opt_a = 0;

    for (int i = start_a; i <= end_a; i++)
    {
        int start_b = 0, end_b = 40000;
        while (end_b - start_b >= 3)
        {
            int mid1 = (2 * start_b + end_b) / 3;
            int mid2 = (start_b + 2 * end_b) / 3;

            if (func(i, mid1) < func(i, mid2))
            {
                start_b = mid1;
            }
            else
            {
                end_b = mid2;
            }
        }

        double max_for_mid = max(func(i, start_b), max(func(i, start_b+1), func(i, start_b+2)));

        if (max_for_opt_a < max_for_mid)
        {
            max_for_opt_a = max_for_mid;
        }
    }

    printf("%.3lf\n", max_for_opt_a);
}

void init()
{
    scanf("%lf %lf", &x, &p);
    p /= 100;
    x /= 100;
    arr[0] = 1;
    arr[1] = (1-p) / p;
}

int main(void)
{
    init();
    solve();
    return 0;
}
