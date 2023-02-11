#include <bits/stdc++.h>
using namespace std;
int arr[1050][1050];
int n;

int func(int x, int y, int z, int w)
{
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    v.push_back(w);
    sort(v.begin(),v.end());
    return v[1];
}

int divide_and_conquer(int a, int b, int idx)
{
    if (idx==1)
    {
        return arr[a][b];
    }
    return func(divide_and_conquer(a, b, idx/2), 
               divide_and_conquer(a+idx/2, b, idx/2),
               divide_and_conquer(a, b+idx/2, idx/2),
               divide_and_conquer(a+idx/2, b+idx/2, idx/2)
               );
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n",divide_and_conquer(1,1,n));
}