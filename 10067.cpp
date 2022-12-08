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

#define MAX 100005

class Line 
{
public:
    ll a, b;
    Line(ll a=0, ll b=0) : a(a), b(b) {}
};

class CHT
{
private:
    ll s=0,e=0;
    Line d[MAX];
    int idx[MAX];
public:
    double cross(int a, int b)
    {
        return double(d[a].b - d[b].b) / (d[b].a - d[a].a);
    }
    void insert(Line l, int i)
    {
        d[e]=l;
        idx[e]=i;
        while(s<e&& (d[e].a==d[e-1].a)&&d[e-1].b<=d[e-1].b)
        {
            d[e-1] = d[e];
            idx[e-1] = idx[e];
            e--;
        }
        while(s+1<e&& cross(e-2, e-1)>cross(e,e-1))
        {
            d[e-1]=d[e];
            idx[e-1]=idx[e];
            e--;
        }
        e++;
    }
    pr<ll,ll> query(ll x)
    {
        while(s+1 < e && d[s+1].a*x+d[s+1].b >= d[s].a*x+d[s].b)
        {
            s++;
        }
        return {d[s].a*x+d[s].b,idx[s]};
    }
    void clear()
    {
        s=e=0;
    }
};


int n, m;
ll dp[2][MAX];
ll arr[MAX];
int pre[202][MAX];
CHT cht;
void solve()
{
    fe(i,1,m)
    {
        cht.clear();
        fe(j, 1, n)
        {
            pr<ll,ll> t=cht.query(arr[j]);
            dp[i%2][j]=t.first;
            pre[i][j]=t.second;
            Line l(arr[j],dp[(i-1)%2][j]-arr[j]*arr[j]);
            cht.insert(l,j);
        }
    }

    pnlld1(dp[m%2][n]);
    int now = n;
    vt<int> ans;
    for(int i=m; i>=1; i--)
    {
        ans.pb(pre[i][now]);
        now=pre[i][now];
    }
    sort(ans.begin(),ans.end());
    f(i,0,m)
    {
        psd1(ans[i]);
    }
}

void init()
{
    sd2(n,m);

    f(i,1,n+1)
    {
        slld1(arr[i]);
        arr[i]+=arr[i-1];
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}