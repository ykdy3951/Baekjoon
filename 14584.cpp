#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;
int n;

int main(void)
{
    cin >> s;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        v.push_back(t);
    }
    bool flag = false;
    for(int i = 0; i < 26; i++)
    {
        string t = "";
        for(char j : s)
        {
            t+=char(((j-97)+i)%26+97);
        }
        for(string tmp : v)
        {
            if(t.find(tmp) != string::npos)
            {
                cout << t << endl;
                flag=true;
                break;
            }
        }    
        if (flag)
            break;
    }

    return 0;
}