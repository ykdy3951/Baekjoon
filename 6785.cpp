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

int t;
int m,a,b;
bool chk;
void solve(int size, int x, int y)
{
    if (size == 0) return;
    if (chk) return;

    if (a >= x + size && a < x + 4 * size && b >= y && b < y + size) {
        chk=true;
        return;
    }

    if (a >= x + 2 * size && a < x + 3 * size && b >= y + size && b < y + 2 * size) {
        chk=true;
        return;
    }

    solve(size/5, size, size);
    solve(size/5, 2*size, 2*size);
    solve(size/5, 3*size, size);
}

void init()
{
    sd1(t);
    while(t--) {
        sd3(m,a,b);
        chk=false;
        solve(int(pow(5, m-1)), 0, 0);

        printf(chk ? "crystal\n" : "empty\n");
    }
}

int main(void)
{
    init();
    return 0;
}