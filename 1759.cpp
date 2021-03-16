#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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
#define f(i, a, b) for (i = a; i < b; i++)

int l, c;
vector<string> v;

void init()
{
    sd2(l, c);

    int i;
    f(i, 0, c)
    {
        string ch;
        cin >> ch;
        v.push_back(ch);
    }

    st(v);
}

void solve(string str, int s, int e, int cnt, int ae, int wk)
{
    int i;

    if (cnt == -1)
    {
        if (ae >= 1 && wk >= 2)
            cout << str << endl;

        return;
    }

    f(i, s, e - cnt)
    {
        if (v[i] == "a" || v[i] == "e" || v[i] == "i" || v[i] == "o" || v[i] == "u")
            solve(str + v[i], i + 1, e, cnt - 1, ae + 1, wk);
        else
            solve(str + v[i], i + 1, e, cnt - 1, ae, wk + 1);
    }
}

int main(void)
{
    init();

    string str = "";

    solve(str, 0, c, l - 1, 0, 0);

    return 0;
}