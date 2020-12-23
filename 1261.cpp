#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define INF_ 987654321

struct M
{
    int x, y, d;
    bool operator<(const M t) const { return d > t.d; }
};

int n,
    m;
int arr[MAX][MAX];
int dis[MAX][MAX];
priority_queue<M> pq;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &arr[i][j]);
            dis[i][j] = INF_;
        }
    }
}

int dijkstra()
{
    pq.push({1, 1, 0});
    dis[1][1] = 0;
    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y, d = pq.top().d;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > m || ny < 1 || ny > n)
                continue;
            int nd = d + arr[nx][ny];
            if (dis[nx][ny] > nd)
            {
                dis[nx][ny] = nd;
                pq.push({nx, ny, nd});
            }
        }
    }
    return dis[m][n];
}

int main(void)
{
    init();
    printf("%d\n", dijkstra());

    return 0;
}