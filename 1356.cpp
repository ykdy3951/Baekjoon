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

string s;

void init()
{
    cin >> s;
}

void solve()
{
    int i, j, k;
    f(i, 1, s.length())
    {
        int tmp1 = 1, tmp2 = 1;
        f(j, 0, i)
        {
            tmp1 *= (s[j] - '0');
        }
        f(k, i, s.length())
        {
            tmp2 *= (s[k] - '0');
        }
        if (tmp1 == tmp2)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main(void)
{
    fio;
    init();
    solve();
    return 0;
}