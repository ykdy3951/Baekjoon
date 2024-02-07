#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

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

rope<char> r;
string s;
int q;
int cmd, a, b;

void solve()
{
    fio;
    cin >> s;
    r.append(s.c_str());
    cin >> q;

    while (q--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> a >> b;
            r = r.substr(a, b - a + 1) + r.substr(0, a) + r.substr(b + 1, r.size() - b - 1);
        }
        else if (cmd == 2)
        {
            cin >> a >> b;
            r = r.substr(0, a) + r.substr(b + 1, r.size() - b - 1) + r.substr(a, b - a + 1);
        }
        else {
            cin >> a;
            cout << r[a] << endl;
        }
    }
}

int main(void)
{
    solve();
    return 0;
}