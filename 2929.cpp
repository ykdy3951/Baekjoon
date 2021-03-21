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
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define pnd1(a) printf("%d\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define pr pair
#define pb push_back
#define f(i, a, b) for (i = a; i < b; i++)

string s;
string d[4] = {
    "",
    "a",
    "aa",
    "aaa"};

void init()
{
    cin >> s;
}

void solve()
{
    int i = 0, j = 0;
    int cnt = 0;
    f(i, 0, s.length())
    {
        if (s[i] - 'a' < 0 && (i % 4))
        {
            int tmp = 4 - (i % 4);
            cnt += tmp;
            s = s.substr(0, i) + d[tmp] + s.substr(i);
            i = i + tmp;
        }
    }
    cout << cnt << endl;
}

int main(void)
{
    fio;
    init();
    solve();
    return 0;
}