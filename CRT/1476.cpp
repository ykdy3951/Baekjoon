#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    int i = 1;
    while (true)
    {
        if (!((i - a) % 15 || (i - b) % 28 || (i - c) % 19))
        {
            cout << i;
            return 0;
        }
        i++;
    }
}