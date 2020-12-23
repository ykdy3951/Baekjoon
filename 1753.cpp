#include <bits/stdc++.h>

using namespace std;

#define MAX 20001
#define INF_ 987654321

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[MAX];
int ans[MAX];
int v, e;
int k;

void dijkstra()
{
    pq.push({0, k});
    while (!pq.empty())
    {
        int now = pq.top().second;
        int weight = -pq.top().first;
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
    scanf("%d %d", &v, &e);
    scanf("%d", &k);

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= v; i++)
        ans[i] = INF_;
    ans[k] = 0;
}

int main(void)
{
    init();
    dijkstra();

    for (int i = 1; i <= v; i++)
    {
        if (ans[i] == INF_)
            printf("INF\n");
        else
            printf("%d\n", ans[i]);
    }

    return 0;
}