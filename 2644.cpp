#include <bits/stdc++.h>

using namespace std;

int n, m;
int p, q;
int x, y;
vector<int> v[101];
bool chk[101];
queue<pair<int, int>> Q;

void bfs()
{
    Q.push({p, 0});
    chk[p] = true;
    while (!Q.empty())
    {
        int a = Q.front().first, b = Q.front().second;
        Q.pop();
        for (int i : v[a])
        {
            if (i == q)
            {
                cout << b + 1 << endl;
                return;
            }
            if (!chk[i])
            {
                chk[i] = true;
                Q.push({i, b + 1});
            }
        }
    }
    cout << -1 << endl;
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> p >> q;
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs();
    return 0;
}