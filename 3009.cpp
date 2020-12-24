#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> vx, vy;
int x, y;

void init()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &a, &b);
        vx.push_back(a);
        vy.push_back(b);
    }
}

void solve()
{
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    int num = 0;
    for (int i : vx)
    {
        if (vx[0] == i)
        {
            num++;
        }
    }
    if (num == 2)
    {
        x = vx[2];
    }
    else
    {
        x = vx[0];
    }

    num = 0;
    for (int i : vy)
    {
        if (vy[0] == i)
        {
            num++;
        }
    }
    if (num == 2)
    {
        y = vy[2];
    }
    else
    {
        y = vy[0];
    }
}

int main(void)
{
    init();
    solve();
    printf("%d %d", x, y);
    return 0;
}