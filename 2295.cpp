#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<int> w;

map<int, int> m;

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            w.push_back(v[i]+v[j]);
        }
    }

    for(int i = n - 1; i >= 1; i--)
        for(int j = i - 1; j >= 0; j--)
            m[v[i]-v[j]] = max(v[i], m[v[i]-v[j]]);

    int ans=0;
    for(int i : w)
    {
        if (m.count(i))
            ans=max(ans,m[i]);
    }

    printf("%d\n", ans);
    return 0;
}