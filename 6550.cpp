#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    char x[100001], y[100001];
    while(scanf("%s %s", x, y) == 2)
    {
        int idx = 0, l = strlen(x);

        for(int i = 0; i < strlen(y); i++)
        {
            if (y[i] == x[idx])
            {
                idx++;
                if (idx == l)
                {
                    break;                
                }
            }
        }

        if (idx == l)
            printf("Yes\n");
        else
            printf("No\n");        
    }
    
    return 0;
}