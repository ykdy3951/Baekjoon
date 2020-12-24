#include <bits/stdc++.h>

using namespace std;

int x, y;

void init()
{
    scanf("%d", &x);
    scanf("%d", &y);
}

int main(void)
{
    init();
    if (x > 0)
    {
        if (y > 0)
        {
            printf("1");
        }
        else
        {
            printf("4");
        }
    }
    else
    {
        if (y > 0)
        {
            printf("2");
        }
        else
        {
            printf("3");
        }
    }
    return 0;
}