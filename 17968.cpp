#include <iostream>
#include <cstdio>
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

int n;
int arr[1005]={1,1,};

void init()
{
    sd1(n);
}

void solve()
{
    fe(i,2,n)
    {
        bool flag[1500]={false,};
        for(int k = 1; 2 * k <= i; k++)
        {
            int x = 2*arr[i-k]-arr[i-2*k];
            if (x > 0)
                flag[x]=true;
        }

        f(num,1,1500)
        {
            if (!flag[num]) 
            {
                arr[i]=num;
                break;
            }
        }
    }
    pnd1(arr[n]);
}

int main(void)
{
    init();
    solve();
    return 0;
}
