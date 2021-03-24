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
#define pnd1(a) printf("%d\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define pr pair
#define pb push_back
#define f(i, a, b) for (i = a; i < b; i++)

#define MAX 12

int n, arr[MAX];
int oper[4];
int resMax = INT_MIN;
int resMin = INT_MAX;

void init()
{
    sd1(n);
    int i;
    f(i, 0, n)
    {
        sd1(arr[i]);
    }
    sd4(oper[0], oper[1], oper[2], oper[3]);
}

int calculator(int a, int b, int oper)
{
    if (oper == 0)
    {
        return a + b;
    }
    else if (oper == 1)
    {
        return a - b;
    }
    else if (oper == 2)
    {
        return a * b;
    }
    else if (oper == 3)
    {
        bool f = false;
        if (a < 0)
        {
            f = true;
            a = -a;
        }
        int result = a / b;
        return (f ? -result : result);
    }
}

void solve(int res, int operCnt)
{
    if (operCnt == n - 1)
    {
        resMin = min(resMin, res);
        resMax = max(resMax, res);
        return;
    }

    int i;
    f(i, 0, 4)
    {
        if (!oper[i])
            continue;
        oper[i] -= 1;
        int tmp = calculator(res, arr[operCnt + 1], i);
        solve(tmp, operCnt + 1);
        oper[i] += 1;
    }
}

int main(void)
{
    init();
    solve(arr[0], 0);
    pnd1(resMax);
    pnd1(resMin);
    return 0;
}