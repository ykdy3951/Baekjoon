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

int tc;

void solve(string op, string arr, int num)
{
    deque<int> d;

    int i = 1;
    while (i < arr.length())
    {
        string temp = "\n";
        while (1)
        {
            if (arr[i] == ',' || arr[i] == ']')
            {
                break;
            }
            else
            {
                temp += arr[i];
                i++;
            }
        }
        if (temp == "\n")
        {
            break;
        }
        else
        {
            d.pb(stoi(temp));
            i++;
        }
    }

    int r = 1;
    f(i, 0, op.length())
    {
        if (op[i] == 'R')
        {
            r *= -1;
        }
        else
        {
            if (d.empty())
            {
                cout << "error" << endl;
                return;
            }
            else
            {
                if (r == 1)
                {
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }
    }

    cout << "[";
    if (r == 1)
    {
        while (!d.empty())
        {
            int num = d.front();
            d.pop_front();

            cout << num;
            if (!d.empty())
            {
                cout << ",";
            }
        }
    }
    else
    {
        while (!d.empty())
        {
            int num = d.back();
            d.pop_back();

            cout << num;
            if (!d.empty())
            {
                cout << ",";
            }
        }
    }
    cout << "]" << endl;
}

void init()
{
    cin >> tc;
    while (tc--)
    {
        string op, arr;
        int num;
        cin >> op;
        cin >> num;
        cin >> arr;
        solve(op, arr, num);
    }
}

int main(void)
{
    fio;
    init();
    return 0;
}