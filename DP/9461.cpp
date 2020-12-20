#include <bits/stdc++.h>

using namespace std;

int tc;

vector<long long> v;

void init()
{
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    scanf("%d", &tc);
}

void solve()
{
    while (tc--)
    {
        int num;
        scanf("%d", &num);
        for (int i = v.size() + 1; i <= num; i++)
        {
            v.push_back(v[v.size() - 1] + v[v.size() - 5]);
        }
        printf("%lld\n", v[num - 1]);
    }
}

int main()
{
    init();
    solve();
    return 0;
}