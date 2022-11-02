#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define INF 987654321
#define sc1(a) scanf("%c", &a)
#define ss1(a) scanf("%s", s)
#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d %d", &a, &b)
#define sd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define sld1(a) scanf("%ld", &a)
#define sld2(a, b) scanf("%ld %ld", &a, &b)
#define slld1(a) scanf("%lld", &a)
#define slld2(a, b) scanf("%lld %lld", &a, &b)
#define pd1(a) printf("%d", a)
#define psd1(a) printf("%d ", a)
#define pnd1(a) printf("%d\n", a)
#define plld1(a) printf("%lld", a)
#define pslld1(a) printf("%lld ", a)
#define pnlld1(a) printf("%lld\n", a)
#define pd2(a, b) printf("%d %d", a, b)
#define pnd2(a, b) printf("%d %d\n", a, b)
#define st(v) sort(v.begin(), v.end())
#define vt vector
#define pr pair
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int n, q;

class SegTree {
public:
    int size;
    vt<ll> tree;

    SegTree()
    {
    }

    SegTree(int n)
    {
        for(size=1; size<n; size*=2);
        tree.resize(2*size);
    }

    void update(int pos, ll n) {
        int idx=pos+size-1;
        ll val = n - tree[idx];
        while(idx) {
            tree[idx]+=val;
            idx/=2;
        }
    }

    ll getSum(int pos, int left, int right, int start, int end)
    {
        if (right < start || left > end) return 0;
        if (start >= left && end <= right) return tree[pos];
        int mid = (start + end) / 2;
        return getSum(pos*2, left, right, start, mid) + getSum(pos*2+1, left, right, mid+1, end);
    }
};

SegTree tree;

void solve()
{
    while(q--)
    {
        int x, y, a, b;
        sd4(x, y, a, b);
        if (x > y) {
            int tmp = x;
            x=y;
            y=tmp;
        }
        pnlld1(tree.getSum(1, x, y, 1, tree.size));
        tree.update(a, b);
    }
}

void init()
{
    sd2(n,q);
    tree=SegTree(n);
    for(int i = 1; i <= n; i++)
    {
        ll x;
        slld1(x);        
        tree.update(i,x);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}