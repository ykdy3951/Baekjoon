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

class Line 
{
public:
    ll a, b; // a is slope and b is y-intercept
    double s;
    Line(ll a = 0, ll b = 0, double s = 0) : a(a), b(b), s(s) {}

    bool operator<(const Line &l) const
    {
        return s < l.s;
    }

    double cross(const Line &l)
    {
        return double(b-l.b) / (l.a-a);
    }
};

ll A[100005], B[100005], DP[100005];
int n;
Line L[100005];

void solve()
{
    stack<Line> s;
    int top=0, fpos=0;
    f(i,1,n)
    {
        Line l(B[i-1],DP[i-1]);
        while(top > 0)
        {
            l.s=l.cross(L[top-1]);
            if (l.s > L[top-1].s) break;

            --top;
            if (top == fpos) fpos--;
        }
        L[top++] = l;

        ll x = A[i];
        while(fpos+1 < top && L[fpos+1].s < x) fpos++;
        DP[i]=L[fpos].a*x+L[fpos].b;
    }
    pnlld1(DP[n-1]);
}

void init()
{
    sd1(n);
    f(i,0,n)
    {
        slld1(A[i]);
    }
    f(i,0,n)
    {
        slld1(B[i]);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}