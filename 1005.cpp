#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> dp, par, arr;
int tc, n, k, w;

void solve()
{
    scanf("%d", &tc);
    while (tc--)
    {
        dp.clear();
        graph.clear();
        par.clear();
        arr.clear();
        queue<int> q;

        scanf("%d %d", &n, &k);

        graph.resize(n + 1);
        arr.resize(n + 1);
        par.resize(n + 1);
        dp.resize(n + 1);

        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            par[y]++;
        }

        scanf("%d", &w);

        for (int i = 1; i <= n; i++)
        {
            if (par[i] == 0)
            {
                q.push(i);
                dp[i] = arr[i];
            }
        }

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            if (now == w)
            {
                break;
            }
            for (int next : graph[now])
            {
                if (--par[next] == 0)
                {
                    q.push(next);
                }

                if (dp[next] < dp[now] + arr[next])
                {
                    dp[next] = dp[now] + arr[next];
                }
            }
        }

        printf("%d\n", dp[w]);
    }
}

int main(void)
{
    solve();
    return 0;
}
