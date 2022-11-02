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
    vt<int> minTree;
    vt<int> maxTree;

    SegTree() {}
    SegTree(int n) 
    {
        for(size=1;size<n;size*=2);
        minTree=vt<int>(2*size,1000000005);
        maxTree=vt<int>(2*size,0);
    }
    void update(int pos, int val) 
    {
        int idx=pos+size-1;
        minTree[idx]=val;
        maxTree[idx]=val;
        idx/=2;
        while(idx)
        {
            minTree[idx]=min(minTree[idx*2],minTree[idx*2+1]);
            maxTree[idx]=max(maxTree[idx*2],maxTree[idx*2+1]);
            idx/=2;
        }
    }
    int getMin(int pos, int fir, int sec, int start, int end)
    {
        if (sec < start || fir > end) return 1000000005;
        if (start >= fir && end <= sec) return minTree[pos];
        int mid=(start+end)/2;
        return min(getMin(pos*2, fir, sec, start, mid), getMin(pos*2+1, fir, sec, mid+1, end));
    }
    int getMax(int pos, int fir, int sec, int start, int end)
    {
        if (sec < start || fir > end) return 0;
        if (start >= fir && end <= sec) return maxTree[pos];
        int mid=(start+end)/2;
        return max(getMax(pos*2, fir, sec, start, mid), getMax(pos*2+1, fir, sec, mid+1, end));
    }
};

int n, m;
SegTree tree;

void solve()
{
    while(m--)
    {
        int a, b;
        sd2(a, b);
        pnd2(tree.getMin(1, a, b, 1, tree.size), tree.getMax(1, a, b, 1, tree.size));
    }
}

void init()
{
    sd2(n,m);
    tree=SegTree(n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        sd1(x);
        tree.update(i,x);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}