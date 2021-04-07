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

int n, m;
int LS[101];

void init()
{
    sd2(n, m);
    while (n--)
    {
        int a, b;
        sd2(a, b);
        LS[a] = b;
    }

    while (m--)
    {
        int a, b;
        sd2(a, b);
        LS[a] = b;
    }
}

void solve()
{
    queue<int> q;
    q.push(1);

    vt<int> arr(101, -1);
    arr[1] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        fe(i, 1, 6)
        {
            int next = node + i;
            if (next > 100)
                continue;

            if (LS[next] != 0)
            {
                next = LS[next];
            }

            if (arr[next] == -1)
            {
                arr[next] = arr[node] + 1;
                q.push(next);
            }
        }
    }

    pnd1(arr[100]);
}

int main(void)
{
    init();
    solve();
    return 0;
}