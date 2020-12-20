#include <bits/stdc++.h>

using namespace std;

struct loc
{
    int rx, ry, bx, by, cnt;
};

int rx, ry, bx, by;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string arr[10];
bool chk[10][10][10][10];
int n, m;
queue<loc> q;

void moving(int &x, int &y, int &c, int dx, int dy)
{
    while (arr[x + dx][y + dy] != '#' && arr[x][y] != 'O')
    {
        x += dx;
        y += dy;
        c += 1;
    }
}
void bfs()
{

    while (!q.empty())
    {
        int rx = q.front().rx, ry = q.front().ry;
        int bx = q.front().bx, by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();
        if (cnt >= 10)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, ncnt = cnt + 1;
            moving(nrx, nry, rc, dx[i], dy[i]);
            moving(nbx, nby, bc, dx[i], dy[i]);
            if (arr[nbx][nby] == 'O')
                continue;
            if (arr[nrx][nry] == 'O')
            {
                cout << ncnt;
                return;
            }
            if ((nrx == nbx) && (nry == nby))
            {
                if (rc > bc)
                    nrx -= dx[i], nry -= dy[i];
                else
                    nbx -= dx[i], nby -= dy[i];
            }
            if (chk[nrx][nry][nbx][nby])
                continue;
            chk[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, ncnt});
        }
    }
    cout << -1;
}

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'B')
            {
                bx = i, by = j;
            }
            if (arr[i][j] == 'R')
            {
                rx = i, ry = j;
            }
        }
    }
    q.push({rx, ry, bx, by, 0});
    chk[rx][ry][bx][by] = true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    bfs();

    return 0;
}