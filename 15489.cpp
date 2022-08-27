#include <iostream>
#include <algorithm>
#include <vector>

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

int r,c,w;
ll dp[35][35];
ll ans;

void init()
{
    sd3(r,c,w);
}

void solve()
{
    f(i,1,r+w)
    {
        f(j,1,i+1)
        {
            if (i == j || j == 1) dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    
    int t=1;
    f(i,r,r+w)
    {
        f(j,c,c+t)
        {
            ans+=dp[i][j];
        }
        t++;
    }
}

int main(void)
{
    init();
    solve();
    pnlld1(ans);
    return 0;
}
