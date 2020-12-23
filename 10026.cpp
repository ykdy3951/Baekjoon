#include <bits/stdc++.h>

using namespace std;

int n;
string arr[2][101];
bool chk[2][101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int answer[2] = {
    0,
};

void bfs(int k)
{
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !chk[k][nx][ny])
            {
                if (arr[k][x][y] == arr[k][nx][ny])
                {
                    q.push({nx, ny});
                    chk[k][nx][ny] = true;
                }
            }
        }
    }
}

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
        arr[1][i] = arr[0][i];
        for (int j = 0; j < n; j++)
        {
            if (arr[1][i][j] == 'G')
            {
                arr[1][i][j] = 'R';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!chk[0][i][j])
            {
                q.push({i, j});
                bfs(0);
                answer[0]++;
            }
            if (!chk[1][i][j])
            {
                q.push({i, j});
                bfs(1);
                answer[1]++;
            }
        }
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}