#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define INF 987654321
#define sc1(a) scanf("%c", &a)
#define ss1(a) scanf("%s", a)
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

#define mod 1000000007

int n;
int k[1000001], ck[1000001], ock[1000001];
char s[1000001];
ll ans = 0;

void solve()
{
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
            k[i] = k[i+1];
            ck[i] = ck[i+1];
            ock[i] = ock[i+1];
        }

        if (s[i] == 'K') {
            k[i]++;
        } else if (s[i] == 'C') {
            ck[i] = (ck[i] + k[i]) % mod;
        } else if (s[i] == 'O') {
            ock[i] = (ock[i] + ck[i]) % mod;
        }
    }

    ll tmp = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            ans = (ans + 1LL * tmp * ock[i]) % mod;
        }
        tmp = (tmp * 2) % mod;
    }

    pnlld1(ans % mod);
}

void init()
{
    sd1(n);
    ss1(s);
}

int main(void)
{
    init();
    solve();
    return 0;
}