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

class SegTree
{
public:
    int size;
    vt<int> tree;
    vt<int> lazy;
    SegTree() {}
    SegTree(int n) 
    {
        for(size=1;size<n;size*=2);
        tree.resize(2*size);
        lazy.resize(2*size);
    }
    void updateLazy(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] = (end-start+1) - tree[node];
            if (start != end)
            {
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            lazy[node]=!lazy[node];
        }
    }
    void updateRange(int node, int start, int end, int left, int right)
    {
        updateLazy(node, start, end);
        if(right < start || end < left) return;

        if(left <= start && end <= right)
        {
            tree[node]=(end-start+1)-tree[node];
            if (start != end)
            {
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            return;
        }

        int mid=(start+end)/2;
        updateRange(node*2,start,mid,left,right);
        updateRange(node*2+1,mid+1,end,left,right);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
    int getSum(int node, int start, int end, int left, int right)
    {
        updateLazy(node, start, end);
        if (right < start || end < left) return 0;

        if(left <= start && end <= right)
        {
            return tree[node];
        }
        int mid=(start+end)/2;
        return getSum(node*2,start,mid,left,right)+getSum(node*2+1,mid+1,end,left,right);
    }
};

SegTree tree;
int n, m;

void solve()
{
    int a, b, c;
    while(m--)
    {
        sd3(a,b,c);
        if(a)
        {
            pnd1(tree.getSum(1,1,tree.size,b,c));
        }
        else
        {
            tree.updateRange(1,1,tree.size,b,c);
        }
    }
}

void init()
{
    sd2(n,m);
    tree=SegTree(n);
}

int main(void)
{
    init();
    solve();
    return 0;
}