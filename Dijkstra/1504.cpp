#include <bits/stdc++.h>

using namespace std;

#define MAX 805
#define INF 987654321

int v[3][MAX];
vector<pair<int, int>> graph[MAX];
int n, e;
int arr[3] = {
    1,
};

void init()
{
    scanf("%d %d", &n, &e);
    for (int j = 0; j <= 2; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            v[j][i] = INF;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    scanf("%d %d", &arr[1], &arr[2]);
}

void dijkstra(int S, int k)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    v[k][S] = 0;
    while (!pq.empty())
    {
        int w = -pq.top().first, a = pq.top().second;
        pq.pop();
        if (v[k][a] < w)
            continue;
        for (auto g : graph[a])
        {
            int na = g.first, nw = g.second;
            if (w + nw < v[k][na])
            {
                pq.push({-(nw + w), na});
                v[k][na] = w + nw;
            }
        }
    }
}

int main()
{
    init();
    for (int i = 0; i <= 2; i++)
    {
        dijkstra(arr[i], i);
    }
    if (v[1][arr[2]] != INF)
    {
        int ans = min(v[0][arr[1]] + v[2][n], v[0][arr[2]] + v[1][n]);
        if (ans >= INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", v[1][arr[2]] + ans);
        }
    }
    else
    {
        printf("-1\n");
    }
}