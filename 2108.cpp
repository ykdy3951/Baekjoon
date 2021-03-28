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
#define f(i, a, b) for (int i = a; i < b; i++)

int n;
vt<int> v;
double s;
map<int, int> m;

void init()
{
    cin >> n;
    f(i, 0, n)
    {
        int num;
        cin >> num;
        s += num;
        m[num]++;
        v.pb(num);
    }
}

void solve()
{
    vt<pr<int, int>> vm(m.begin(), m.end());
    sort(vm.begin(), vm.end(), [](pr<int, int> a, pr<int, int> b) {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    int fre = vm[0].first;
    if (vm[0].second == vm[1].second)
        fre = vm[1].first;

    st(v);

    cout << round(s / n) << endl;
    cout << v[v.size() / 2] << endl;
    cout << fre << endl;
    cout << v.back() - v.front() << endl;
}

int main(void)
{
    fio;
    init();
    solve();
    return 0;
}