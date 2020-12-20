#include <bits/stdc++.h>

using namespace std;

#define MAX 51
#define INF 987654321

struct maze
{
    int x, y, w;
    bool operator<(const maze t) const { return w > t.w; }
};
int n;
int graph[MAX][MAX];
int weight[MAX][MAX];
priority_queue<maze> pq;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            scanf("%1d", &a);
            graph[i][j] = !a;
            weight[i][j] = INF;
        }
    }
}

int dijkstra()
{
    pq.push({0, 0, 0});
    weight[0][0] = 0;
    while (!pq.empty())
    {
        maze t = pq.top();
        pq.pop();
        int x = t.x, y = t.y, w = t.w;
        if (x == n - 1 && y == n - 1)
            return (weight[x][y] == INF) ? 0 : weight[x][y];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            int nw = w + graph[nx][ny];
            if (weight[nx][ny] > nw)
            {
                weight[nx][ny] = nw;
                pq.push({nx, ny, nw});
            }
        }
    }
}

int main()
{
    init();
    printf(
        "%d\n", dijkstra());
}