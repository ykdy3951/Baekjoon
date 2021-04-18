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
#define pnd3(a, b, c) printf("%d %d %d\n", a, b, c);
#define st(v) sort(v.begin(), v.end())
#define vt vector
#define pr pair
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int arr[4][4];
int ans = 8;
int st[8], rotCnt[8], rc[8];

void init()
{
	f(i, 0, 4)
	{
		f(j, 0, 4) 
		{
			sd1(arr[i][j]);
		}
	}
}

void rowRot(int cnt)
{
	int tmp = arr[cnt][3];
	for(int i = 3; i > 0; i--)
	{
		arr[cnt][i] = arr[cnt][i - 1];
	}
	arr[cnt][0] = tmp;
}

void colRot(int cnt)
{
	int tmp = arr[3][cnt];
	for(int i = 3; i > 0; i--)
	{
		arr[i][cnt] = arr[i - 1][cnt];
	}
	arr[0][cnt] = tmp;
}

int solve(int size, int r, int c)
{
	int difCnt = 0;
	f(i, 0, 16)
	{
		difCnt += (arr[i / 4][i % 4] != i + 1);
	}

	if(ans <= size + (difCnt + 3) / 4)
		return 0;
	
	if(difCnt == 0)
	{
		ans = size;
		return 1;
	}

	int rv = 0;
	f(i, r, 4)
	{
		f(j, 1, 4)
		{
			rowRot(i);
			if(solve(size + 1, i + 1, 0)) {
				rc[size] = 1, rotCnt[size] = j, st[size] = i + 1;
				rv = 1;
			}
		}
		rowRot(i);
	}
	
	f(i, c, 4)
	{
		f(j, 1, 4)
		{
			colRot(i);
			if(solve(size + 1, 0, i + 1))
			{
				rc[size] = 2, rotCnt[size] = j, st[size] = i + 1;
				rv = 1;
			}
		}
		colRot(i);
	}

	return rv;
}

int main(void)
{
    init();
    solve(0, 0, 0);
	pnd1(ans);
	f(i, 0, ans)
	{
		pnd3(rc[i], st[i], rotCnt[i]);
	}
    return 0;
}
