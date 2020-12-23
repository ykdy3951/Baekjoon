#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<pair<int, int>> pq;
vector<int> arr;
vector<int> len;

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pq.push({-a, b});
    }
    while (!pq.empty())
    {
        arr.push_back(pq.top().second);
        pq.pop();
    }
}

void dp_lis()
{
    for (int k = 0; k < n; k++)
    {
        len.push_back(1);
        for (int i = 0; i < k; i++)
        {
            if (arr[i] < arr[k])
            {
                len[k] = max(len[k], len[i] + 1);
            }
        }
    }
}

int main(void)
{
    init();
    dp_lis();
    printf("%d\n", n - *max_element(len.begin(), len.end()));
    return 0;
}