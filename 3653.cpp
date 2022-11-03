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

class FenwickTree {
public:
    int size;
    vt<int> tree;

    FenwickTree() {}
    FenwickTree(int n) 
    {
        size=n;
        tree.resize(n);
    }
    void update(int pos, int val) 
    {
        while(pos <= size)
        {
            tree[pos]+=val;
            pos+=(pos&-pos);
        }
    }
    int sum(int pos)
    {
        int ret=0;
        while(pos)
        {
            ret+=tree[pos];
            pos-=(pos&-pos);
        }
        return ret;
    }
};

int t, n, m, pos[100005];

void solve()
{
    sd1(t);
    while(t--)
    {
        sd2(n,m);
        FenwickTree tree(n+m);

        for(int i = 1; i <= n; i++) {
            pos[i]=m+i;
            tree.update(m+i, 1);
        }

        for(;m>=1;m--)
        {
            int t;
            sd1(t);
            psd1(tree.sum(pos[t]-1));
            tree.update(pos[t],-1);
            tree.update(m,1);
            pos[t]=m;
        }
        printf("\n");
    }
}

int main(void)
{
    solve();
    return 0;
}