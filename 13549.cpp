#include <bits/stdc++.h>

using namespace std;

#define MAX 200002
#define INF 987654321

int v[MAX];
typedef pair<int, int> P;
int n, k;
priority_queue<P> pq;

P func(int a, int w, int u)
{
    if (u == 0)
    {
        return {
            -(w + 1), a + 1};
    }
    else if (u == 1)
    {
        return {-(w + 1), a - 1};
    }
    else
    {
        return {-w, a * 2};
    }
}

void init()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 2 * max(n, k); i++)
    {
        v[i] = INF;
    }
}

int dijkstra()
{
    pq.push({0, n});
    v[n] = 0;
    while (!pq.empty())
    {
        int w = -pq.top().first, a = pq.top().second;
        if (a == k)
        {
            return w;
        }
        pq.pop();
        if (v[a] < w)
            continue;
        for (int i = 0; i <= ((a) ? 2 : 1); i++)
        {
            P p = func(a, w, i);
            if (p.second < 0 || p.second > MAX)
                continue;
            if (-p.first < v[p.second])
            {
                v[p.second] = -p.first;
                pq.push(p);
            }
        }
    }
}

int main(void)
{
    init();
    printf("%d\n", dijkstra());
    return 0;
}