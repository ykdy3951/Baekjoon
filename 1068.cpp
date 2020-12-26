#include <bits/stdc++.h>

using namespace std;

vector<int> node[51];
int d, n;
int start;
int ans;
void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num == -1)
        {
            start = i;
            continue;
        }
        node[num].push_back(i);
    }
    scanf("%d", &d);
}

void dfs(int s)
{
    if (s == d)
        return;
    if (node[s].empty())
    {
        ans++;
        return;
    }
    for (int i = 0; i < node[s].size(); i++)
    {
        if (node[s].size() == 1 && node[s][i] == d)
            ans++;
        else
        {
            dfs(node[s][i]);
        }
    }
}

int main(void)
{
    init();
    dfs(start);
    printf("%d\n", ans);
    return 0;
}