#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m;
ll cost[2501];
ll dist[2501][2501];
priority_queue<pair<ll, pair<ll, ll>>> pq;
vector<pair<ll, ll>> graph[2501];

void init()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &cost[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        scanf("%lld %lld %lld", &x, &y, &w);
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    memset(dist, -1, sizeof(dist));
    pq.push({0, {1, cost[1]}});
}

ll dijkstra()
{
    while (!pq.empty())
    {
        ll w = -pq.top().first, now = pq.top().second.first, min_cost = pq.top().second.second;
        pq.pop();

        if (dist[now][min_cost] != -1)
            continue;
        dist[now][min_cost] = w;
        if (now == n)
        {
            return w;
        }

        for (auto next : graph[now])
        {
            if (dist[next.first][min(min_cost, cost[next.first])] != -1)
                continue;
            pq.push({-w - next.second * min_cost, {next.first, min(min_cost, cost[next.first])}});
        }
    }
}

int main(void)
{
    init();
    printf("%lld\n", dijkstra());
    return 0;
}