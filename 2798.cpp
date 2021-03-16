#include <bits/stdc++.h>

using namespace std;

#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d %d", &a, &b)
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define pnd1(a) printf("%d\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define sort_v(v) sort(v.begin(), v.end())
#define f(i, a, b) for (i = a; i < b; i++)

int n, m;
vector<int> v;

void init()
{
    sd2(n, m);

    int i;
    f(i, 0, n)
    {
        int a;
        sd1(a);
        v.push_back(a);
    }
}

int solve()
{
    sort_v(v);

    int ans = 0;

    int i, j, k;
    f(i, 0, n - 2)
    {
        f(j, i + 1, n - 1)
        {
            f(k, j + 1, n)
            {
                int tmp = v[i] + v[j] + v[k];
                if (tmp <= m)
                {
                    ans = max(ans, tmp);
                }
                else
                {
                    break;
                }
            }
        }
    }

    return ans;
}

int main(void)
{
    init();
    int ans = solve();

    pnd1(ans);
    return 0;
}