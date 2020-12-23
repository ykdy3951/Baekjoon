#include <bits/stdc++.h>

using namespace std;

string a, b;
int sum;

int main(void)
{

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '5' || a[i] == '6')
        {
            a[i] = '5';
            sum += pow(10, a.length() - 1 - i);
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '5' || b[i] == '6')
        {
            b[i] = '5';
            sum += pow(10, a.length() - 1 - i);
        }
    }
    int ans = stoi(a) + stoi(b);
    cout << ans << " " << ans + sum << endl;

    return 0;
}