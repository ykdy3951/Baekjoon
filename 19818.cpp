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

vector<string> v1, v2, v;
map<string, string> m;

void init()
{
    string s;
    bool flag = false;
    string::size_type n1;
    string::size_type n2;
    while (getline(cin, s))
    {
        if (s == "\\begin{thebibliography}{99}")
            flag = true;
        if (s == "\\end{thebibliography}")
        {
            break;
        }
        if (flag)
        {
            while (true)
            {
                n1 = s.find("\\bibitem{");
                n2 = s.find("}");
                if (n1 == string::npos || n2 == string::npos)
                {
                    break;
                }
                string key = s.substr(n1 + 9, n2 - n1 - 9);
                v2.pb(key);
                m.insert({key, s});
                s = s.substr(n2 + 1);
            }
        }
        else
        {
            while (true)
            {
                n1 = s.find("\\cite{");
                n2 = s.find("}");
                if (n1 == string::npos || n2 == string::npos)
                {
                    break;
                }
                v1.pb(s.substr(n1 + 6, n2 - n1 - 6));
                s = s.substr(n2 + 1);
            }
        }
    }
}

void solve()
{
    int i;
    bool flag = true;
    f(i, 0, v1.size())
    {
        if (v1[i] != v2[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Correct" << endl;
    }
    else
    {
        cout << "Incorrect" << endl;
        cout << "\\begin{thebibliography}{99}" << endl;
        f(i, 0, v1.size())
        {
            cout << m.find(v1[i])->second << endl;
        }
        cout << "\\end{thebibliography}" << endl;
    }
}

int main(void)
{
    fio;
    init();
    solve();
    return 0;
}