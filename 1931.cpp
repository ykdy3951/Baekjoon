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
vt<pr<int, int>> arr;

bool compare(pr<int, int> a, pr<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}
void init()
{
    sd1(n);

    pr<int, int> v;
    f(i, 0, n)
    {
        sd2(v.first, v.second);
        arr.pb(v);
    }
}

void solve()
{
    sort(arr.begin(), arr.end(), compare);

    int cnt = 1;
    pr<int, int> pre = arr[0];
    f(i, 1, n)
    {
        if (pre.second <= arr[i].first)
        {
            cnt++;
            pre = arr[i];
        }
    }

    pnd1(cnt);
}

int main(void)
{
    init();
    solve();
    return 0;
}