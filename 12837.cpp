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

class SegTree {
public:
    int size;
    vt<ll> tree;
    SegTree() {}
    SegTree(int n)
    {
        for(size=1;size<n;size*=2);
        tree.resize(2*size);
    }
    void update(int pos, ll val)
    {
        int idx=pos+size-1;
        while(idx)
        {
            tree[idx]+=val;
            idx/=2;
        }
    }

    ll getSum(int pos, int fir, int sec, int start, int end)
    {
        if (sec < start || fir > end) return 0;
        if (start >= fir && end <= sec) return tree[pos];
        int mid = (start + end) / 2;
        return getSum(pos*2, fir, sec, start, mid) + getSum(pos*2 + 1, fir, sec, mid+1, end);
    }
};

SegTree tree;
int n, q;

void solve()
{
    while(q--)
    {
        int a, b, c;
        sd3(a, b, c);
        if (a == 1) 
        {
            tree.update(b, c);
        }
        else
        {
            pnlld1(tree.getSum(1, b, c, 1, tree.size));
        }
    }
}

void init()
{
    sd2(n, q);
    tree=SegTree(n);
}

int main(void)
{
    init();
    solve();
    return 0;
}