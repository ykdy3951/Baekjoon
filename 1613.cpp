#include <bits/stdc++.h>

using namespace std;

int n, k;
int s;
vector<int> v[401];
int vst[401][401];
queue<int> q;

vector<int> ans;

void graph_traversal(int x)
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

        for (int i : v[now])
        {
            if (!vst[x][i])
                q.push(i);
        }
    }
}

void solve()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
    }

    scanf("%d", &s);
    for (int i = 0; i < s; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (!vst[x][x])
        {
            graph_traversal(x);
        }
        if (!vst[y][y])
        {
            graph_traversal(y);
        }

        if (vst[x][y])
        {
            ans.push_back(-1);
        }
        else if (vst[y][x])
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
    }
}

int main(void)
{
    solve();
    for (int i : ans)
    {
        printf("%d\n", i);
    }
    return 0;
}