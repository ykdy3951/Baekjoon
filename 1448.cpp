#include <bits/stdc++.h>
using namespace std;
#define sd1(a) scanf("%d", &a)
int n;
vector<int> v;
int main(void)
{
    sd1(n);
    int t;
    for(int i = 0; i < n; i++)
    {
        sd1(t);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());

    int ans = -1;
    for(int i = 0; i < n - 2; i++)
    {
        if(v[i] < v[i+1] + v[i+2])
        {
            ans = v[i] + v[i+1] + v[i+2];
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}