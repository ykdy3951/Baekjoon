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
#define slld3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
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

#define MAX 1000005

class Line {
public:
    ll a, b;
    Line(ll a=0, ll b=0) : a(a), b(b) {}
};

class ConvexHull_Trick {
private:
    int s = 0, e = 0;
    Line arr[MAX];
    int idx[MAX];
public:
    double cross(int a, int b)
    {
        return double(arr[a].b - arr[b].b) / (arr[b].a - arr[a].a);
    }
    void insert(Line v, int line_idx)
    {
        arr[e]=v;
        idx[e]=line_idx;
        while(s+1 < e && cross(e-2, e-1) > cross(e-1, e))
        {
            arr[e-1]=arr[e];
            idx[e-1]=idx[e];
            e--;
        }
        e++;
    }
    pr<ll,ll> query(ll x)
    {
        while(s+1 < e && arr[s+1].b-arr[s].b >= x * (arr[s].a - arr[s+1].a))
        {
            s++;
        }
        return pr<ll,ll>(arr[s].a*x+arr[s].b, idx[s]);
    }
    pr<ll,ll> query2(ll x)
    {
        int l = 0, r = e-1;
        while(l != r)
        {
            int m = (r + l) / 2;
            if (cross(m, m+1) <= x) l = m+1;
            else r=m;
        }
        return pr<ll,ll>(arr[l].a*x+arr[l].b, idx[l]);
    }
    void clear(){s=e=0;}
};

int n;
ll a, b, c;
ll x[MAX];
ll sum[MAX];
ll dp[MAX];
ConvexHull_Trick cht;

void solve()
{
    Line l;
    l.a=b;
    l.b=0;

    cht.insert(l,0);
    f(i,1,n+1)
    {
        dp[i]=c+a*sum[i]*sum[i]+cht.query2(sum[i]).first;
        l.a=-2*a*sum[i]+b;
        l.b=dp[i]-b*sum[i]+a*sum[i]*sum[i];
        cht.insert(l,i);
    }
    pnlld1(dp[n]);
}

void init()
{
    sd1(n);
    slld3(a,b,c);
    f(i,1,n+1)
    {
        slld1(x[i]);
        sum[i]=sum[i-1]+x[i];
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}