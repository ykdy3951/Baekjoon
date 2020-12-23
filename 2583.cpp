#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100

using namespace std;

int n, m, k;
int section = 0;
bool map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
vector<int> ret;

void init()
{
    scanf("%d %d %d", &n, &m, &k);
    while (k--)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                map[i][j] = 1;
    }
}

void bfs(int x, int y)
{
    int cnt = 1;
    map[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && !map[nx][ny])
            {
                map[nx][ny] = 1;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    section++;
    ret.push_back(cnt);
}

int main(void)
{
    init();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!map[i][j])
            {
                bfs(i, j);
            }
        }
    }

    printf("%d\n", section);
    sort(ret.begin(), ret.end());

    for (int i = 0; i < section; i++)
        printf("%d ", ret[i]);
    return 0;
}
