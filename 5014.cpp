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

int f, s, g, u, d;
bool chk[1000001];

queue<pii> q;

void solve()
{
    q.push({0, s});
    chk[s] = true;

    if (s == g) 
    {
        pnd1(0);
        return;
    }

    while(!q.empty())
    {
        int now = q.front().second, cost = q.front().first;
        q.pop();

        if (now - d >= 1 && !chk[now-d]) {
            if (now - d == g) 
            {
                pnd1(cost + 1);
                return;
            }
            q.push({cost + 1, now - d});
            chk[now - d] = true;
        }

        if (now + u <= f && !chk[now+u]) {
            if (now + u == g)
            {
                pnd1(cost + 1);
                return;
            }
            q.push({cost + 1, now + u});
            chk[now + u] = true;
        }
    }

    printf("use the stairs\n");
}

void init()
{
    sd3(f, s, g);
    sd2(u, d);
}

int main(void)
{
    init();
    solve();
    return 0;
}