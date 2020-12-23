#include <bits/stdc++.h>

using namespace std;

#define INF 100000000000
#define ll long long

int n, m, k;
vector<pair<int, int>> graph[10001];
priority_queue<pair<ll, pair<int, int>>> pq;
vector<vector<ll>> dist(10001, vector<ll>(21, INF));
ll ans;

void init()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    for (int i = 0; i < 21; i++)
    {
        dist[1][i] = 0;
    }
}

void dijkstra()
{
    pq.push({-dist[1][0], {1, 0}});

    while (!pq.empty())
    {
        ll w = -pq.top().first;
        int now = pq.top().second.first, cnt = pq.top().second.second;
        pq.pop();

        if (dist[now][cnt] != w)
            continue;

        for (pair<int, int> next : graph[now])
        {
            if (dist[next.first][cnt] > w + next.second)
            {
                dist[next.first][cnt] = w + next.second;
                pq.push({-dist[next.first][cnt], {next.first, cnt}});
            }

            if (cnt == k)
                continue;

            if (dist[next.first][cnt + 1] > w)
            {
                dist[next.first][cnt + 1] = w;
                pq.push({-dist[next.first][cnt + 1], {next.first, cnt + 1}});
            }
        }
    }
}

int main(void)
{
    init();
    dijkstra();

    ans = INF;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dist[n][i]);
    }

    printf("%lld\n", ans);
    return 0;
}