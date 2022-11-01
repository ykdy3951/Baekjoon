#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegTree {
public:
    int size;
    vector<ll> tree;
    
    SegTree(int cnt)
    {
        for(size=1; size<cnt; size*=2);
        tree.resize(size*2);
    }
    
    void update(int pos, ll val)
    {
        int idx = size + pos - 1;
        ll num = val - tree[idx];
        while(idx) {
            tree[idx]+=num;
            idx/=2;
        }
    }
    
    ll getSum(int pos, int left, int right, int st, int ed)
    {
        if (right < st || left > ed) return 0;
        if (st >= left && ed <= right) return tree[pos];
        int mid = (st + ed) / 2;
        return getSum(pos * 2, left, right, st, mid) + getSum(pos * 2 + 1, left, right, mid + 1, ed);
    }
};

int n, m, k;

int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    SegTree segTree(n);
    for(int i = 1; i <= n; i++)
    {
        ll num;
        scanf("%lld", &num);
        segTree.update(i, num);
    }

    int a, b;
    ll c;
    for(int i = 0; i < m + k; i++)
    {
        scanf("%d %d %lld", &a, &b, &c);

        if(a == 1)
        {
            segTree.update(b, c);
        }
        else
        {
            printf("%lld\n", segTree.getSum(1, b, c, 1, segTree.size));
        }
    }
    return 0;
}