#include <bits/stdc++.h>

using namespace std;

#define fio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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

int t;

void solve()
{
    sd1(t);
    while (t--)
    {
        int a, b;
        sd2(a, b);
        queue<pr<int, int>> q;
        priority_queue<int> pq;
        f(i, 0, a)
        {
            int n;
            sd1(n);
            q.push({n, i});
            pq.push(n);
        }

        int cnt = 0;
        bool flag = false;

        while (!pq.empty())
        {
            int target = pq.top();
            pq.pop();

            while (true)
            {
                pr<int, int> print = q.front();
                q.pop();

                if (print.first == target)
                {
                    if (print.second == b)
                    {
                        flag = true;
                    }
                    cnt++;
                    break;
                }
                q.push(print);
            }

            if (flag)
            {
                pnd1(cnt);
                break;
            }
        }
    }
}

int main(void)
{
    solve();
    return 0;
}