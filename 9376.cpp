#include <bits/stdc++.h>

using namespace std;

int tc;
int h, w;

#define INF 987654321

char arr[102][102];
int chk[3][102][102];
int sumArr[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
deque<pair<int, int>> dq;

void bfs()
{
    dq.push_back({0, 0});
    for (int i = 0; i < 3; i++)
    {
        int x = dq.back().first, y = dq.back().second;
        dq.pop_back();
        deque<pair<int, int>> q;
        q.push_back({x, y});
        chk[i][x][y] = 0;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop_front();
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)
                    continue;
                if (chk[i][nx][ny] >= 0 || arr[nx][ny] == '*')
                    continue;
                if (arr[nx][ny] == '.')
                {
                    chk[i][nx][ny] = chk[i][x][y];
                    q.push_front({nx, ny});
                }
                else if (arr[nx][ny] == '#')
                {
                    chk[i][nx][ny] = chk[i][x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
}

void init()
{
    scanf("%d", &tc);
    while (tc--)
    {
        memset(chk, -1, sizeof(chk));
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
                    arr[i][j] = '.';
                else
                    scanf(" %1c", &arr[i][j]);
                if (arr[i][j] == '$')
                {
                    arr[i][j] = '.';
                    dq.push_back({i, j});
                }
            }
        }
        bfs();
        int ans = INF;
        for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                sumArr[i][j] = 0;
                if (arr[i][j] == '#')
                {
                    sumArr[i][j] -= 2;
                }
                sumArr[i][j] += chk[0][i][j] + chk[1][i][j] + chk[2][i][j];
                if (sumArr[i][j] != -3)
                {
                    ans = min(ans, sumArr[i][j]);
                }
            }
        }
        printf("%d\n", ans);
    }
}

int main(void)
{
    init();
    return 0;
}