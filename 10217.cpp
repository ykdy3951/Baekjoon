#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int t, n, m, k, cache[102][10002];
class Info
{
public:
    int v, x, d;
    Info(int v, int x, int d) : v(v), x(x), d(d)
    {
    }
};
struct cmp
{
    bool operator()(Info x, Info y)
    {
        return x.d > y.d;
    }
};
vector<Info> adj[102];
int dijkstra()
{
    int ret = INF;
    priority_queue<Info, vector<Info>, cmp> pq;
    memset(cache, -1, sizeof(cache));
    cache[1][0] = 0;
    pq.push(Info(1, 0, 0));
    while (!pq.empty())
    {
        Info cur = pq.top();
        pq.pop();
        if (cur.d > cache[cur.v][cur.x] || cur.x > m)
            continue;
        for (int i = 0; i < adj[cur.v].size(); i++)
        {
            Info tmp = adj[cur.v][i];
            int acCost = tmp.x + cur.x;
            if ((cache[tmp.v][acCost] == -1 || cache[tmp.v][acCost] > cur.d + tmp.d) && cur.x + tmp.x <= m)
            {
                cache[tmp.v][acCost] = cur.d + tmp.d;
                pq.push(Info(tmp.v, acCost, cur.d + tmp.d));
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        if (cache[n][i] != -1 && ret > cache[n][i])
            ret = cache[n][i];
    }
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i <= 101; i++)
            adj[i].clear();
        int u, v, x, d;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d %d %d", &u, &v, &x, &d);
            adj[u].push_back(Info(v, x, d));
        }
        int tmp = dijkstra();
        printf(tmp == INF ? "Poor KCM\n" : "%d\n", tmp);
    }
}