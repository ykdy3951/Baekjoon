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

char p[3200][6300];
int n;

void print(int n, int x, int y) {
    
    if (n == 3) {
		p[y][x] = '*';
		p[y + 1][x - 1] = '*';
		p[y + 1][x + 1] = '*';
		p[y + 2][x - 2] = '*';
		p[y + 2][x - 1] = '*';
		p[y + 2][x] = '*';
		p[y + 2][x + 1] = '*';
		p[y + 2][x + 2] = '*';
		return;
	}

	print(n / 2, x, y);
	print(n / 2, x - (n / 2), y + (n / 2));
	print(n / 2, x + (n / 2), y + (n / 2));
}

int main(void) {

    sd1(n);
    f(i, 0, n) {
        f(j, 0, 2*n-1) {
            p[i][j] = ' ';
        }
    }
    print(n,n-1,0);
    f(i, 0, n) {
        f(j, 0, 2*n-1) {
            printf("%c",p[i][j]);
        }
        printf("\n");
    }

    return 0;
}