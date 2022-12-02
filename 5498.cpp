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

#define MAX 10005

class Line {
public:
    ll a, b;
    Line(ll a=0, ll b=0) : a(a), b(b) {}
};

class ConvexHull_Trick {
private:
    deque<Line> arr;
public:
    double cross(int a, int b)
    {
        return double(arr[a].b - arr[b].b) / (arr[b].a - arr[a].a);
    }
    void insert(Line v)
    {
        arr.push_back(v);
        while(arr.size() > 1 && cross(0, 1) < cross(arr.size()-1, 0)) 
        {
            arr.pop_front();
        }
        arr.pop_back();
        arr.push_front(v);
    }
    ll query(ll x)
    {
        while(arr.size() > 1 && arr[arr.size()-2].a*x+arr[arr.size()-2].b <= arr.back().a*x+arr.back().b)
        {
            arr.pop_back();
        }
        return arr.back().a*x+arr.back().b;
    }
};

int n;
int s;
ll tsum[MAX];
ll fsum[MAX];
ll dp[MAX];
ConvexHull_Trick cht;

void solve()
{
    Line l;
    l.a=-tsum[n];
    l.b=fsum[n]*tsum[n];

    cht.insert(l);
    for(int i = n; i >= 1; i--)
    {
        dp[i]=(s-tsum[i-1])*(fsum[n]-fsum[i-1])+cht.query(fsum[i-1]);
        l.a=-tsum[i-1];
        l.b=dp[i]+tsum[i-1]*fsum[n];
        cht.insert(l);
    }
    pnlld1(dp[1]);
}

void init()
{
    sd1(n);
    sd1(s);
    f(i,1,n+1)
    {
        slld2(tsum[i], fsum[i]);
        tsum[i]+=tsum[i-1];
        fsum[i]+=fsum[i-1];
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}