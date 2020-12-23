#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

int n, m;
vector<pair<int, int>> ans;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[1005];
int p[1005], dist[1005];

void init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = MAX;
    }
}

void dijkstra()
{
    dist[1] = 0;
    pq.push({-dist[1], 1});
    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int w = graph[now][i].second;

            if (dist[next] > dist[now] + w)
            {
                dist[next] = dist[now] + w;
                pq.push({-dist[next], next});

                p[next] = now;
            }
        }
    }
}

int main(void)
{
    init();
    dijkstra();
    printf("%d\n", n - 1);
    for (int i = 2; i <= n; i++)
    {
        printf("%d %d\n", p[i], i);
    }
    return 0;
}