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

int a, b, c;
bool chk[205][205];
int x, y, z;

void solve()
{
    queue<pii> q;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        int k = c - (i+j);
        q.pop();

        if (chk[i][j]) continue;
        chk[i][j]=true;
        
        if (i > 0)
        {
            if (b-j-i >= 0)
            {
                q.push({0, j+i});
            }
            else
            {
                q.push({i-(b-j), b});
            }
            if (c-k-i >= 0)
            {
                q.push({0, j});
            }
            else
            {
                q.push({i-(c-k), j});
            }
        }

        if (j > 0)
        {
            if (a-i-j >= 0)
            {
                q.push({j+i, 0});
            }
            else
            {
                q.push({a, j-(a-i)});
            }
            if (c-k-j >= 0)
            {
                q.push({i, 0});
            }
            else
            {
                q.push({i, j-(c-k)});
            }
        }

        if (k > 0)
        {
            if (k >= a-i)
            {
                q.push({a, j});
            }
            else
            {
                q.push({i+k, j});
            }
            if (k >= b-j)
            {
                q.push({i, b});
            }
            else
            {
                q.push({i,j+k});
            }
        }
    }

    vector<int> v;
    for(int i = 0; i <= b; i++)
    {
        if (chk[0][i]) v.pb(c-i);
    }
    sort(v.begin(),v.end());

    for(int i : v)
    {
        psd1(i);
    }
    printf("\n");
}

void init()
{
    sd3(a, b, c);
    x = 0, y = 0, z = c;

    solve();
}

int main(void)
{
    init();
    return 0;
}