#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int tc;
int n;

typedef pair<ll, ll> p;
vector<p> s;

void solve()
{
    scanf("%d", &tc);
    while (tc--)
    {
        s.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            s.push_back({x, y});
        }
        ll MN = 0x7fffffffffffffffLL;
        vector<int> bf(n);
        fill(bf.begin() + n / 2, bf.end(), 1);
        do
        {
            p val = {0, 0};
            for (int i = 0; i < n; i++)
            {
                if (bf[i])
                {
                    val.first += s[i].first;
                    val.second += s[i].second;
                }
                else
                {
                    val.first -= s[i].first;
                    val.second -= s[i].second;
                }
            }
            MN = min(MN, val.first * val.first + val.second * val.second);
        } while (next_permutation(bf.begin(), bf.end()));
        printf("%lf\n", (double)sqrt((double)MN));
    }
}

int main(void)
{
    solve();
    return 0;
}