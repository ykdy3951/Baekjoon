#include <bits/stdc++.h>

using namespace std;

#define MAX 1001
#define INF_ 987654321

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[MAX];
int ans[MAX];
int n, m;
int s, e;

int dijkstra()
{
    pq.push({0, s});
    while (!pq.empty())
    {
        int now = pq.top().second;
        int weight = -pq.top().first;
        if (now == e)
            return weight;
        pq.pop();
        for (auto next : graph[now])
        {
            if (ans[next.first] >= weight + next.second)
            {
                ans[next.first] = weight + next.second;
                pq.push({-ans[next.first], next.first});
            }
        }
    }
}

void init()
{
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
        ans[i] = INF_;

    scanf("%d", &s);
    scanf("%d", &e);

    ans[s] = 0;
}

int main(void)
{
    init();
    printf("%d", dijkstra());

    return 0;
}