#include <bits/stdc++.h>

using namespace std;

int num;
int arr[505][505];

void init()
{
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void DP()
{
    for (int i = num - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }
}

int main(void)
{
    init();
    DP();
    printf("%d\n", arr[0][0]);
}