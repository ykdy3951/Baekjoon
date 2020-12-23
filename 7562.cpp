#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t;
int l;
bool arr[301][301];

int xx1, xx2, yy1, yy2;
queue<pair<pair<int, int>, int>> q;
vector<int> v;
int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second, cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < l && 0 <= ny && ny < l && !arr[nx][ny])
            {
                if (nx == xx2 && ny == yy2)
                {
                    v.push_back(cnt + 1);
                    return;
                }
                q.push({{nx, ny}, cnt + 1});
                arr[nx][ny] = 1;
            }
        }
    }
}

bool init()
{
    q = queue<pair<pair<int, int>, int>>();
    memset(arr, 0, sizeof(arr));
    cin >> l;
    cin >> xx1 >> yy1;
    cin >> xx2 >> yy2;
    q.push({{xx1, yy1}, 0});
    arr[xx1][yy1] = true;
    return ((xx1 == xx2) && (yy1 == yy2));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        if (init())
        {
            v.push_back(0);
        }
        else
        {
            bfs();
        }
    }

    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}