#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> graph[205];
int result[205][205];

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int j = 0; j < graph[i].size(); j++)
        {
            pq.push({-(graph[i][j].second), {graph[i][j].first, graph[i][j].first}});
        }
        while (!pq.empty())
        {
            int w = -pq.top().first, node = pq.top().second.first, par = pq.top().second.second;
            pq.pop();

            if (result[i][node])
            {
                continue;
            }
            else
            {
                result[i][node] = par;
            }
            for (int j = 0; j < graph[node].size(); j++)
            {
                pq.push({-(graph[node][j].second + w), {graph[node][j].first, par}});
            }
        }
    }
}

int main(void)
{
    init();
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", result[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}