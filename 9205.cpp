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
#define pii pair<int,int>
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int t;
int n;
bool chk[105];

void solve()
{
    sd1(t);
    while(t--)
    {
        vector<pii> v;
        sd1(n);
        memset(chk, 0, sizeof(chk));

        pii t;
        f(i, 0, n + 2)
        {
            sd2(t.first, t.second);
            v.pb(t);
        }
        queue<int> q;
        q.push(0);
        chk[0] = true;
        while(!q.empty() && !chk[n+1])
        {
            int now = q.front();
            q.pop();

            f(i, 1, n+2)
            {
                if (abs(v[i].first - v[now].first) + abs(v[i].second - v[now].second) > 1000) continue;
                if (chk[i]) continue;

                q.push(i);
                chk[i] = true;
            }
        }

        if (chk[n+1])
        {
            printf("happy\n");
        }
        else
        {
            printf("sad\n");
        }
    }
}

int main(void)
{
    solve();
    return 0;
}