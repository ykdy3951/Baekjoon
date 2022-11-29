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

class Dot
{
public:
    int x, y, p, q;

    Dot(int x=0, int y=0) : x(x), y(y), p(1), q(0) {}
};

bool comp(const Dot &a, const Dot &b)
{
    if (a.p * b.q != a.q * b.p)
        return a.p * b.q < a.q * b.p;
    
    if (a.y != b.y) return a.y > b.y;

    return a.x < b.x;
}

int ccw(const Dot &a, const Dot &b, const Dot &c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

Dot arr[55];
int t, n;

void solve()
{
    stack<int> s;

    int nxt = 2;
    s.push(0);
    s.push(1);

    while(nxt < n)
    {
        while(s.size() >= 2)
        {
            int sec = s.top();
            s.pop();
            int fir = s.top();

            if (ccw(arr[fir], arr[sec], arr[nxt]) < 0)
            {
                s.push(sec);
                break;
            }
        }

        s.push(nxt++);
    }

    pnd1(s.size());
    
    stack<pr<int,int>> t;
    while(s.size())
    {
        t.push({arr[s.top()].x, arr[s.top()].y});
        s.pop();
    }

    while(t.size())
    {
        pnd2(t.top().first,t.top().second);
        t.pop();
    }
}

void init()
{
    sd1(t);
    while(t--)
    {
        sd1(n);
        int x, y;
        f(i,0,n)
        {
            sd2(x,y);
            arr[i]=Dot(x,y);
        }

        sort(arr,arr+n,comp);

        f(i,1,n)
        {
            arr[i].p=arr[i].x-arr[0].x;
            arr[i].q=arr[i].y-arr[0].y;
        }

        sort(arr+1, arr+n, comp);

        solve();
    }
}

int main(void)
{
    init();
    return 0;
}