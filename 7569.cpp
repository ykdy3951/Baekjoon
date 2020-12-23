#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int arr[101][101][101];
bool chk[101][101][101] = {
    false,
};
int sum = 0;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs()
{
    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second.first;
        int day = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = a + dx[i], ny = b + dy[i], nz = c + dz[i], nd = day + 1;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && 1 <= nz && nz <= h && !chk[nz][nx][ny])
            {
                q.push({{nx, ny}, {nz, nd}});
                chk[nz][nx][ny] = true;
                sum++;
            }
        }

        if (sum == n * m * h)
        {
            return day + 1;
        }
    }
    return -1;
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    for (int k = 1; k <= h; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int num;
                cin >> num;
                arr[k][i][j] = num;
                if (num == 1)
                {
                    chk[k][i][j] = true;
                    q.push({{i, j}, {k, 0}});
                    sum++;
                }
                else if (num == -1)
                {
                    chk[k][i][j] = true;
                    sum++;
                }
            }
        }
    }
    if (sum == n * m * h)
        cout << 0 << endl;
    else
    {
        cout << bfs() << endl;
    }
    return 0;
}