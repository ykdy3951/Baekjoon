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

deque<int> d;
int n, m;
queue<int> q;

void init()
{
    sd2(n, m);
    int i;
    f(i, 0, m)
    {
        int num;
        sd1(num);
        q.push(num);
    }
    f(i, 1, n + 1)
    {
        d.pb(i);
    }
}

void solve()
{
    int res = 0;
    while (!q.empty())
    {
        int cnt = 0;
        int target = q.front();
        q.pop();

        while (d.front() != target)
        {
            int x = d.front();
            d.pop_front();
            d.push_back(x);
            cnt++;
        }
        cnt = min(cnt, int(d.size()) - cnt);
        d.pop_front();
        res += cnt;
    }
    pnd1(res);
}

int main(void)
{
    init();
    solve();
    return 0;
}