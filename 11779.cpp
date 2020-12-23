#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n, m;
int s, e;
vector<int> ans;
int dst[1005], trace[1005];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[1005];

void init()
{
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        graph[x].push_back({y, w});
    }

    scanf("%d %d", &s, &e);

    for (int i = 1; i <= n; i++)
    {
        dst[i] = INF;
    }
}

void dijkstra()
{
    pq.push({0, s});
    dst[s] = 0;
    while (!pq.empty())
    {
        int w = -pq.top().first, node = pq.top().second;
        pq.pop();

        if (node == e)
        {
            return;
        }

        if (w != dst[node])
            continue;

        for (pair<int, int> i : graph[node])
        {
            int tw = i.second, tnode = i.first;
            if (dst[tnode] > w + tw)
            {
                dst[tnode] = w + tw;
                trace[tnode] = node;
                pq.push({-dst[tnode], tnode});
            }
        }
    }
}

int main(void)
{
    init();
    dijkstra();

    int trc = e;
    while (trc)
    {
        ans.push_back(trc);
        trc = trace[trc];
    }
    printf("%d\n%ld\n", dst[e], ans.size());
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
