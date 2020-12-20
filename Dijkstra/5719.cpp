#include <bits/stdc++.h>

using namespace std;

#define MAX 502
#define INF 987654321

int n, m;
int s, d;
int G[MAX][MAX];
int ans[MAX];

void init()
{
    scanf("%d %d", &s, &d);
    memset(G, -1, sizeof(G));
    for (int i = 0; i < m; i++)
    {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        G[u][v] = p;
    }
}

void dijkstra()
{
    memset(ans, -1, sizeof(ans));
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        int weight = -pq.top().first, node = pq.top().second;
        pq.pop();
        if (ans[node] != -1)
            continue;
        ans[node] = weight;
        for (int i = 0; i < n; i++)
        {
            if (G[node][i] == -1)
                continue;
            if (ans[i] != -1)
                continue;
            pq.push({-weight - G[node][i], i});
        }
    }
}

void erase()
{
    queue<int> q;
    q.push(d);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (ans[node] == ans[i] + G[i][node] && G[i][node] != -1)
            {
                G[i][node] = -1;
                q.push(i);
            }
        }
    }
}

int main(void)
{

    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n + m == 0)
        {
            return 0;
        }
        init();
        dijkstra();
        erase();
        dijkstra();

        printf("%d\n", ans[d]);
    }

    return 0;
}