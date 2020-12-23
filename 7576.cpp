#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1001][1001];
bool chk[1001][1001] = {
    false,
};
int sum = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;

int bfs()
{
    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int day = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i], ny = b + dy[i], nd = day + 1;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !chk[nx][ny])
            {
                q.push({{nx, ny}, nd});
                chk[nx][ny] = true;
                sum++;
            }
        }

        if (sum == n * m)
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

    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
            if (num == 1)
            {
                chk[i][j] = true;
                q.push({{i, j}, 0});
                sum++;
            }
            else if (num == -1)
            {
                chk[i][j] = true;
                sum++;
            }
        }
    }

    if (sum == n * m)
        cout << 0 << endl;
    else
    {
        cout << bfs() << endl;
    }
    return 0;
}