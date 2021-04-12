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

int n;
int post[100001], inorder[100001];

void init()
{
    sd1(n);

    f(i, 0, n)
    {
        int num;
        sd1(num);
        inorder[num] = i;
    }

    f(i, 0, n)
    {
        int num;
        sd1(num);
        post[i] = num;
    }
}

void solve(int si, int ei, int sj, int ej)
{
    if (si > ei || sj > ej)
        return;

    int root = post[ej];
    psd1(root);

    solve(si, inorder[root] - 1, sj, sj + (inorder[root] - si) - 1);
    solve(inorder[root] + 1, ei, sj + (inorder[root] - si), ej - 1);
}

int main(void)
{
    init();
    solve(0, n - 1, 0, n - 1);
    printf("\n");
    return 0;
}