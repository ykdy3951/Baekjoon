#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n, d;
vector<pair<int, int>> graph[10001];
priority_queue<pair<int, int>> pq;
vector<int> dist(10001, INF);

void init()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        graph[x].push_back({y, w});
    }
}

int dijkstra(int s, int e)
{
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        int now = pq.top().second, w = -pq.top().first;
        pq.pop();
        if (dist[now] < w)
            continue;
        for (pair<int, int> i : graph[now])
        {
            int next = i.first;
            int nw = w + i.second;
            if (nw < dist[next])
            {
                dist[next] = nw;
                pq.push({-nw, next});
            }
        }
        if (now + 1 <= d && dist[now + 1] > w + 1)
        {
            dist[now + 1] = w + 1;
            pq.push({-(w + 1), now + 1});
        }
    }
    return dist[e];
}

int main(void)
{
    init();

    printf("%d\n", dijkstra(0, d));
    return 0;
}