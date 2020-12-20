#include <bits/stdc++.h>

using namespace std;

#define MAX 126
#define INF 987654321

struct Map
{
    int x, y, w;
    bool operator<(const Map t) const { return w > t.w; }
};

int arr[MAX][MAX];
int weight[MAX][MAX];
int n;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void dijkstra()
{
    priority_queue<Map> pq;
    pq.push({0, 0, arr[0][0]});
    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y, w = pq.top().w;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            int nw = w + arr[nx][ny];
            if (weight[nx][ny] > nw)
            {
                weight[nx][ny] = nw;
                pq.push({nx, ny, nw});
            }
        }
    }
}

void init(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
            weight[i][j] = INF;
        }
    }
}

int main(void)
{
    for (int i = 1;; i++)
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        init(n);
        dijkstra();
        printf("Problem %d: %d\n", i, weight[n - 1][n - 1]);
    }
    return 0;
}