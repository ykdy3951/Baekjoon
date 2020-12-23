#include <bits/stdc++.h>

using namespace std;

int n, m;
int x, y;
vector<int> v[101];
bool chk[101];
queue<pair<int, int>> Q;
pair<int, int> p = {-1, 987654321};
int sum;

void bfs(int s)
{
    sum = 0;
    int a, b;
    Q.push({s, 0});
    chk[s] = true;
    while (!Q.empty())
    {
        a = Q.front().first, b = Q.front().second;
        Q.pop();
        for (int i : v[a])
        {
            if (!chk[i])
            {
                chk[i] = true;
                sum += b + 1;
                Q.push({i, b + 1});
            }
        }
    }
    if (sum < p.second)
    {
        p = {s, sum};
    }
    else if (sum == p.second)
    {
        p = {min(s, p.first), sum};
    }
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(chk, 0, sizeof(chk));
        bfs(i);
    }
    cout << p.first;
    return 0;
}