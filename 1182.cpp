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

#define MAX 21

int n, s;
int arr[MAX];
int cnt;

void init()
{
    sd2(n, s);
    int i;
    f(i, 1, n + 1)
    {
        sd1(arr[i]);
    }
}

void solve(int res, int last)
{
    if ((res == s) && last)
    {
        cnt++;
    }

    int i;
    f(i, last + 1, n + 1)
    {
        solve(res + arr[i], i);
    }
}

int main(void)
{
    init();
    solve(0, 0);
    pnd1(cnt);
    return 0;
}