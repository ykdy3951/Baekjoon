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

// Solution
// https://en.wikipedia.org/wiki/Eight_queens_puzzle#Existence_of_solutions
// https://dl.acm.org/doi/10.1145/122319.122322

int n;

void solve()
{
    bool flag=false;
    if (n % 2) {
        flag=true;
        n--;
    }
    if(!(n%2) && n%6!=2)
    {
        for(int i = 1; i <= n / 2; i++) 
            pnd1(i*2);
        for(int i = 1; i <= n / 2; i++)
            pnd1(i*2-1);
    }
    else if (!(n%2) && n % 6 != 0)
    {
        for(int i = 1; i <= n / 2; i++)
            pnd1(1+(2*(i-1)+n/2-1)%n);
        for(int i = n/2; i>=1; i--)
            pnd1(n-(2*(i-1)+n/2-1)%n);
    }
    if (flag)
        pnd1(n+1);
}

void init()
{
    sd1(n);
}

int main(void)
{
    init();
    solve();
    return 0;
}