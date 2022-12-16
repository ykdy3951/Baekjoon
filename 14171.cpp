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
#define pii pair<int,int>
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define fe(i, a, b) for (int i = a; i <= b; i++)

int n, ans;
string arr[200005];
map<string, int> m;

void solve()
{
    f(i,0,n)
    {
        string t = arr[i].substr(2,2)+arr[i].substr(0,2);
        if (arr[i] == t) continue;
        if (m.find(t) == m.end()) continue;
        ans+=m[t];
    }

    cout << ans/2 << endl;
}

void init()
{
    fio;
    cin >> n;
    string a, b;
    f(i,0,n)
    {
        cin >> a >> b;
        arr[i]=a.substr(0,2)+b;
        if(m.find(arr[i]) == m.end())
        {
            m[arr[i]]=0;
        }
        m[arr[i]]+=1;
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}