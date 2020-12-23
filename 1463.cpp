#include <bits/stdc++.h>

using namespace std;

int num;
priority_queue<pair<int, int>> pq;

void init()
{
    scanf("%d", &num);
}

int SOLVE()
{
    pq.push({0, num});
    while (!pq.empty())
    {
        int w = -pq.top().first, num = pq.top().second;
        pq.pop();
        if (num == 1)
        {
            return w;
        }

        w = -(w + 1);
        if (!(num % 3))
        {
            pq.push({w, num / 3});
        }
        if (!(num % 2))
        {
            pq.push({w, num / 2});
        }
        pq.push({w, num - 1});
    }
}

int main(void)
{
    init();
    printf("%d\n", SOLVE());
}