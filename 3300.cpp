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

int t;

void init()
{
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        string tmp = s1;
        tmp.replace(tmp.find("_"), 1, "(.)");
        regex r1(s1);
        regex r2(tmp);
        bool f1 = false, f2 = false;
        smatch match;
        if (regex_match(s2, r1))
            f1 = true;
        if (regex_match(s2, match, r2))
            f2 = true;
        if (f1)
            cout << "_" << endl;
        else if (f2)
        {
            int i;
            f(i, 0, match.size())
            {
                if (match[i].str().length() == 1)
                {
                    tmp = s1;
                    tmp.replace(tmp.find("_"), 1, match[i].str());
                    regex re(tmp);
                    if (regex_match(s2, re))
                    {
                        cout << match[i].str() << endl;
                        break;
                    }
                }
            }
        }
        else
            cout << "!" << endl;
    }
}

void solve()
{
}

int main(void)
{
    fio;
    init();
    // solve();
    return 0;
}