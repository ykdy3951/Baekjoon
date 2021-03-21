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
#define f2(i, a, b) for (i = a; i < b; i += 2)

string s;
int cnt[2];

void init()
{
    cin >> s;
    cnt[0] = count(s.begin(), s.end(), '<');
    cnt[1] = s.length() - cnt[0];
}

void solve(string s, int r, int l)
{
    if (r == 0 && l == 0)
    {
        cout << endl;
        return;
    }
    if (s[0] == '<')
    {
        int i;
        f2(i, 0, s.length())
        {
            if (s[i] == '<')
            {
                cout << "[";
                r--;
            }
            else
            {
                cout << "]";
                l--;
            }
            if (r == l)
            {
                return solve(s.substr(i + 2), r, l);
            }
        }
    }
    else
    {
        int i;
        f2(i, 0, s.length())
        {
            if (s[i] == '>')
            {
                cout << "[";
                r--;
            }
            else
            {
                cout << "]";
                l--;
            }
            if (r == l)
            {
                return solve(s.substr(i + 2), r, l);
            }
        }
    }
}

int main(void)
{
    fio;
    init();
    if (cnt[0] != cnt[1])
    {
        cout << "Keine Loesung" << endl;
        return 0;
    }
    solve(s, cnt[0] / 2, cnt[1] / 2);
    return 0;
}