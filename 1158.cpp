#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;

int main(void) {
    
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    int cnt = 0;
    cout << "<";
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        cnt+=1;

        if(cnt == k)
        {
            cnt=0;
            cout << x;

            if (q.size() == 0)
            {
                cout << ">\n";
            }
            else
            {
                cout << ", ";
            }
        }

        else
        {
            q.push(x);
        }
    }

    return 0;
}