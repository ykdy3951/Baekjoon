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

ll ans;

class SegTree {
public:
    int size;
    vt<int> tree;
    vt<int> height;
    int n;
    SegTree(){}
    SegTree(int n)
    {
        this->n=n;
        for(size=1;size<n;size*=2);
        tree.resize(2*size);
        height.resize(size+1);
    }
    int set(int node, int left, int right)
    {
        if (left == right) return tree[node]=left;
        int mid = (left + right)/2;
        int left_idx = set(node*2,left,mid);
        int right_idx = set(node*2+1,mid+1,right);
        if (height[left_idx]>height[right_idx]) return tree[node]=right_idx;
        else return tree[node]=left_idx;
    }
    int searchST(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start) return -1;
        if (left <= start && end <= right) return tree[node];
        
        int mid=(start + end) / 2;
        int left_idx = searchST(node * 2, start, mid, left, right);
        int right_idx = searchST(node * 2 + 1, mid+1, end, left, right);
        if (left_idx == -1) return right_idx;
        else if (right_idx == -1) return left_idx;
        else if (height[left_idx] > height[right_idx]) return right_idx;
        else return left_idx;
    }
    void find_ans(ll left, ll right)
    {
        if (left < 0 || right > n-1) return;
        int idx=searchST(1,0,n-1,left,right);
        if (height[idx]*(right-left+1)>ans) ans=height[idx]*(right-left+1);
        if (left <= idx-1) find_ans(left,idx-1);
        if (idx+1 <= right) find_ans(idx+1,right);
    }
};

SegTree tree;
int n;

void solve()
{
    sd1(n);
    tree=SegTree(n);
    for(int i = 0; i < n; i++) sd1(tree.height[i]);
    tree.set(1,0,n-1);
    tree.find_ans(0,n-1);
    pnlld1(ans);
}

int main(void)
{
    solve();
    return 0;
}