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
int n,m;
int a, b;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int arr[101][101];
bool chk[101][101];

void solve()
{
    sd1(t);
    while(t--)
    {
        int highest = 0;
        priority_queue<pr<int,pr<int,int>>> pq;
        bool flag=false;
        int ans;

        sd2(n,m);
        f(i,0,n)
        {
            f(j,0,m)
            {
                char c;
                scanf(" %1c", &c);
                arr[i][j] = (c == '#' ? -1 : c - '0');
                highest = max(highest, arr[i][j]);
                chk[i][j] = false;
            }
        }
        sd2(a, b);

        pq.push({0, {a, b}});

        while(!pq.empty())
        {
            int w = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            
            if (chk[x][y]) continue;
            chk[x][y]=true;

            if (arr[x][y] == highest)
            {
                flag=true;
                pnd1(w);
                break;
            }

            for(int i = 0; i < 8; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (arr[nx][ny] == -1) continue;
                int nw = w+(abs(arr[nx][ny]-arr[x][y])+1)*(abs(arr[nx][ny]-arr[x][y])+1);

                pq.push({-nw,{nx,ny}});
            }
        }

        if (!flag) 
        {
            printf("NO\n");
        }
    }
}

int main(void)
{
    solve();
    return 0;
}