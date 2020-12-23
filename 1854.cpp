#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int n, m, k;
priority_queue<int> path[MAX];
vector<pair<int, int>> G[MAX];

void init()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].push_back({b, c});
    }
}

void dijkstra()
{
}