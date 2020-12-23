#include <bits/stdc++.h>

using namespace std;

struct point
{
    int i, j, k;
};
int n, m;
char arr[1001][1001];
int dist[1001][1001][2];
queue<point> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs()
{
    while (!q.empty())
    {
        int x = q.front().i, y = q.front().j, w = q.front().k;
        q.pop();
        if ((x == n - 1) && (y == m - 1))
        {
            return dist[x][y][w];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny][w])
                continue;
            if (arr[nx][ny] == '0')
            {
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx, ny, w});
            }
            if (arr[nx][ny] == '1' && w == 0)
            {
                dist[nx][ny][1] = dist[x][y][w] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
}

int main(void)
{
    init();
    printf("%d\n", bfs());
    return 0;
}