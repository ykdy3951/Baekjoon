#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

string decode;
string num;
string arr[25][25];

string mini(string a, string b)
{
    if (a.length() < b.length()) return a;
    else if (b.length() < a.length()) return b;
    return max(a,b);
}

string solve(int st, int en)
{
    if (st > en) return "EEEEEEEEEEEEEEEEEEEEEEEEEE";
    if (arr[st][en] != "") return arr[st][en];
    if (st == en) return arr[st][en]=decode[num[st]-'0'];
    if (st+1 == en) 
    {
        int n=(num[st]-'0')*10+(num[en]-'0');
        // cout << n << endl;
        if (n < 26)
        {
            return arr[st][en]=decode[n];
        }
        return arr[st][en]=solve(st,st)+solve(en,en);
    }
    return arr[st][en]=mini(mini(solve(st,st)+solve(st+1,en),solve(st,en-1)+solve(en,en)),mini(solve(st,st+1)+solve(st+2,en),solve(st,en-2)+solve(en-1,en)));
}

void init()
{
    for(int tc=1; ;tc++)
    {
        cin >> decode;
        if (decode == "#") break;
        cout << "Problem " << tc << endl;
        while(true)
        {
            cin >> num;
            if (num == "0") break;
            fe(i,0,num.length())
            {
                fe(j,0,num.length())
                {
                    arr[i][j]="";
                }
            }
            cout << solve(0,num.length()-1) << endl;
        }
        cout << endl;
    }
}

int main(void)
{
    fio;
    init();
    return 0;
}
