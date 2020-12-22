#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int item[105];
int ans;
int vst[105];
vector<pair<int, int>> graph[105];

void init()
{
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &item[i]);
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<int, int>> pq;
        memset(vst, 0, (n + 1) * sizeof(int));
        pq.push({0, i});
        int t_ans = 0;
        while (!pq.empty())
        {
            int w = -pq.top().first, now = pq.top().second;
            pq.pop();
            if (vst[now])
            {
                continue;
            }
            t_ans += item[now];
            vst[now] = 1;

            for (pair<int, int> i : graph[now])
            {
                int next = i.first, nw = i.second + w;
                if (m >= nw)
                {
                    pq.push({-nw, next});
                }
            }
        }
        ans = max(t_ans, ans);
    }
}

int main(void)
{
    init();
    dijkstra();
    printf("%d\n", ans);
    return 0;
}