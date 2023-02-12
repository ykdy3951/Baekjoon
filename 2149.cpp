#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

string key;
vector<pair<char,int>> k;
string s;

int main(void)
{
    cin >> key;

    for(int i = 0; i < key.length(); i++)
    {
        k.push_back({key[i], i});
    }

    sort(k.begin(), k.end(), compare);
    
    cin >> s;

    int len1 = key.length();
    int len2 = s.length() / len1;
    vector<string> tmp(len1, "");

    for(int j = 0; j < len1; j++)
    {
        for(int i = 0; i < len2; i++)
        {
            tmp[k[j].second]+=s[j*len2+i];
        }
    }

    string ans = "";
    
    for(int i = 0; i < len2; i++)
    {
        for(int j = 0; j < len1; j++)
        {
            ans += tmp[j][i];
        }
    }
    cout << ans << endl;


    return 0;
}