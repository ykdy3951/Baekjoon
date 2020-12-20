#include <bits/stdc++.h>

using namespace std;

int n, m;
queue<pair<int, int>> q;
bool chk[100001] = {
    false,
};
int bfs()
{
    while (!q.empty())
    {
        int i = q.front().first;
        int second = q.front().second;
        q.pop();
        if (i == n)
        {
            return second;
        }
        int a[] = {i + 1, i - 1, i * 2};
        for (int j = 0; j < 3; j++)
        {
            if (0 <= a[j] && a[j] <= 100000 && !chk[a[j]])
            {
                chk[a[j]] = true;
                q.push({a[j], second + 1});
            }
        }
    }
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    chk[m] = true;
    q.push({m, 0});
    cout << bfs() << endl;

    return 0;
}