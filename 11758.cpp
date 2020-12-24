#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];
int s;

void init()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
}

int solve()
{
    s = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
    if (s > 0)
        return 1;
    else if (s < 0)
        return -1;
    else
        return 0;
}

int main(void)
{
    init();
    printf("%d\n", solve());
    return 0;
}