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

int n, s;
bool chk[100005];
priority_queue<pii> pq;
vt<vt<pii>> G;
int val;

int solve()
{
    pq.push({0, s});
    int ans=0;

    while(!pq.empty())
    {
        int w = -pq.top().first, now = pq.top().second;
        pq.pop();

        if (chk[now]) continue;
        chk[now] = true;
        ans = max(ans, w);

        for(pii next : G[now])
        {
            if (chk[next.first]) continue;
            pq.push({-(w+next.second), next.first});
        }
    }

    return ans;
}

void init()
{
    sd2(n, s);
    G.resize(n+1);

    int a, b, c;
    f(i,0,n-1)
    {
        sd3(a,b,c);
        G[a].pb({b,c});
        G[b].pb({a,c});
        val+=c;
    }

    int ret = solve();

    pnd1(val*2-ret);
}

int main(void)
{
    init();
    return 0;
}