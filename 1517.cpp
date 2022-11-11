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

int n;
ll ans;
vt<pair<ll,int>> arr;

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
    void update(int node, int start, int end, int pos)
    {
        if (pos < start || end < pos) return;
        tree[node]+=1;
        if (start == end) return;
        int mid = (start + end) / 2;
        update(node*2, start, mid, pos);
        update(node*2+1, mid+1, end, pos);
    }
    int getSum(int node, int start, int end, int left, int right)
    {
        if (end < left || start > right) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end)/2;
        return getSum(node * 2, start, mid, left, right) + getSum(node * 2 + 1, mid + 1, end, left, right);
    }
};

SegTree tree;

void solve()
{
    for(int i = 0; i < n; i++)
    {
        ans+=tree.getSum(1, 1, tree.size, arr[i].second+1, tree.size);
        tree.update(1, 1, tree.size, arr[i].second);
    }

    pnlld1(ans);
}

void init()
{
    sd1(n);
    for(int i = 1; i <= n; i++)
    {
        ll t;
        slld1(t);
        arr.pb({t,i});
    }
    stable_sort(arr.begin(), arr.end());
    tree=SegTree(n);
}

int main(void)
{
    init();
    solve();
    return 0;
}