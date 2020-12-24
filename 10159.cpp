#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[101];
int vst[101][101];
queue<int> q;

void init()
{
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
    }
}

void graph_traversal()
{
    for (int x = 1; x <= n; x++)
    {
        q.push(x);
        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            if (vst[x][now])
            {
                continue;
            }

            vst[x][now] = 1;

            for (int i : graph[now])
            {
                if (!vst[x][i])
                    q.push(i);
            }
        }
    }
}

int main(void)
{
    init();
    graph_traversal();
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            if (vst[i][j] ^ vst[j][i])
            {
                ans++;
            }
        }
        printf("%d\n", n - 1 - ans);
    }
}