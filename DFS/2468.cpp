#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
int answer;
bool vst[101][101] = {
    false,
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int Max;

void dfs(int x, int y, int depth)
{
    vst[x][y] = true;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
        {
            if (!vst[nx][ny] && arr[nx][ny] > depth)
                dfs(nx, ny, depth);
        }
    }
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
            Max = max(Max, num);
        }
    }

    for (int d = 0; d <= Max; d++)
    {
        int t = 0;
        memset(vst, 0, sizeof(vst));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] > d && !vst[i][j])
                {
                    dfs(i, j, d);
                    t++;
                }
            }
        }
        answer = max(answer, t);
    }
    cout << answer << endl;
    return 0;
}