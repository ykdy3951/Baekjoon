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
#define pnlld2(a, b) printf("%lld %lld\n", a, b)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define vt vector
#define pr pair
#define pii pair<int,int>
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

class Node
{
public:
    ll x,y,p,q;
    Node(int x = 0, int y = 0) : x(x), y(y), p(1), q(0) {}
};

int n;

bool compare(const Node &a, const Node &b)
{
    if (a.q * b.p != a.p * b.q)
        return a.q * b.p < a.p * b.q;
    
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

ll ccw(const Node &a, const Node &b, const Node &c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

vt<Node> v;

void solve()
{
    sort(v.begin(), v.end(), compare);

    f(i,1,v.size())
    {
        v[i].p=v[i].x-v[0].x;
        v[i].q=v[i].y-v[0].y;
    }

    sort(v.begin()+1, v.end(), compare);

    pnd1(v.size());

    for(int i = v.size() - 1; i >= 1; i--)
    {
        if (ccw(v[0], v[i], v[i-1]) != 0)
        {
            reverse(v.begin()+i,v.end());
            break;
        }
    }
    f(i,0,v.size())
    {
        pnlld2(v[i].x,v[i].y);
    }
}

void init()
{
    sd1(n);
    ll x, y;
    char c;
    f(i,0,n)
    {
        slld2(x,y);
        scanf(" %1c", &c);

        if (c == 'Y')
        {
            v.pb(Node(x,y)); 
        }
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}