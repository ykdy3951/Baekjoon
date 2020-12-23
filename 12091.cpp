#include <bits/stdc++.h>

using namespace std;

int n;

int main(void)
{

    cin >> n;
    string arr[] = {"Vaporeon", "Jolteon", "Flareon"};
    cout << arr[(++n) % 3];
}