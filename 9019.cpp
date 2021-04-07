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
vt<pr<int, int>> v;
void init()
{
    cin >> n;
    pr<int, int> p;
    while (n--)
    {
        cin >> p.first >> p.second;
        v.pb(p);
    }
}

void bfs(int x, int y)
{
    queue<pr<int, string>> q;
    vt<bool> chk(10001, false);

    q.push({x, ""});
    chk[x] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        string b = q.front().second;
        q.pop();

        if (a == y)
        {
            cout << b << endl;
            break;
        }

        int d = (a * 2) % 10000;
        if (!chk[d])
        {
            chk[d] = true;
            q.push({d, b + "D"});
        }

        int s = a - 1;
        if (s == -1)
            s = 9999;
        if (!chk[s])
        {
            chk[s] = true;
            q.push({s, b + "S"});
        }

        int l = (a % 1000) * 10 + (a / 1000);
        if (!chk[l])
        {
            chk[l] = true;
            q.push({l, b + "L"});
        }

        int r = (a / 10) + (a % 10) * 1000;
        if (!chk[r])
        {
            chk[r] = true;
            q.push({r, b + "R"});
        }
    }
}

void solve()
{
    f(i, 0, v.size())
    {
        bfs(v[i].first, v[i].second);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}