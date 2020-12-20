#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
#define INF 987654321

int t;
int n, d, c;
int arr[MAX];
vector<pair<int, int>> graph[MAX];

void init()
{
    scanf("%d %d %d", &n, &d, &c);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = INF;
    }
    for (int i = 0; i < d; i++)
    {
        int a, b, s;
        scanf("%d %d %d", &a, &b, &s);
        graph[b].push_back({a, s});
    }
}

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, c});
    while (!pq.empty())
    {
        int w = -pq.top().first, x = pq.top().second;
        pq.pop();
        if (arr[x] < w)
            continue;
        arr[x] = w;

        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i].first, nw = graph[x][i].second;
            if (arr[nx] > w + nw)
            {
                pq.push({-(w + nw), nx});
            }
        }
    }
}

int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        dijkstra();
        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == INF)
                continue;
            cnt++;
            ans = max(ans, arr[i]);
        }

        printf("%d %d\n", cnt, ans);

        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
    }
    return 0;
}