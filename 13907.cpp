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

int n, m, k;
int s, d;
int dist[1005][1005];
// 거쳐간거의 최솟값
vector<pr<int,int>> G[1005];
vt<int> up;

void solve()
{
    priority_queue<pr<int, pr<int,int>>> pq;
    pq.push({0,{0,s}});
    dist[s][0]=0;
    while(!pq.empty())
    {
        int w = -pq.top().first, c = pq.top().second.first, now = pq.top().second.second;
        pq.pop();

        if (now == d || c == n) continue;

        for(pr<int,int> p : G[now])
        {
            int nxt = p.first, nw = w + p.second;

            if (dist[nxt][c+1] <= nw) continue;
            dist[nxt][c+1] = nw;
            pq.push({-nw, {c+1, nxt}});
        }
    }
    up.pb(0);
    while(k--)
    {
        int tmp;
        sd1(tmp);
        up.pb(tmp);
    }
    for(int a : up)
    {
        int ans = INF;
        f(i,1,n+1)
        {
            if (dist[d][i] != INF)
            {
                dist[d][i]+=a*i;
                ans=min(dist[d][i],ans);
            }
        }
        pnd1(ans);
    }
}

void init()
{
    sd3(n,m,k);
    sd2(s,d);
    f(i,0,m)
    {
        int a, b, c;
        sd3(a,b,c);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    f(i,1,n+1)
    {
        f(j,1,n+1)
        {
            dist[i][j]=INF;
        }
    }
    solve();
}

int main(void)
{
    init();
    return 0;
}