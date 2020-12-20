#include <bits/stdc++.h>

using namespace std;

int Map[51][51];
bool chk[2][51][51];
int r, c;
pair<int, int> Start, End;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;

void bfs(int k)
{
    while (!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && !chk[k][nx][ny])
            {
                if (Map[nx][ny] == 0 || Map[nx][ny] > cnt + 1)
                {
                    Map[nx][ny] = cnt + 1;
                    chk[k][nx][ny] = 1;
                    q.push({{nx, ny}, cnt + 1});
                }
            }
        }
    }
}

void init()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            char c = s[j];
            if (c == 'X')
            {
                chk[0][i][j] = chk[1][i][j] = 1;
            }
            if (c == '*')
            {
                q.push({{i, j}, 0});
                chk[0][i][j] = chk[1][i][j] = 1;
            }
            if (c == 'S')
            {
                Start = {i, j};
                chk[0][i][j] = 1;
            }
            if (c == 'D')
            {
                End = {i, j};
                chk[0][i][j] = 1;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    bfs(0);
    q.push({Start, 0});
    bfs(1);
    if (Map[End.first][End.second])
    {
        cout << Map[End.first][End.second];
    }
    else
    {
        cout << "KAKTUS";
    }

    return 0;
}