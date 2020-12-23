#include <bits/stdc++.h>

using namespace std;

int arr[2][1005];
char s1[1005], s2[1005];
int len1, len2;
void init()
{
    scanf("%s", s1);
    scanf("%s", s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
}

int LCS()
{
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int k = i % 2;
            int w = (i + 1) % 2;
            if (s1[i - 1] == s2[j - 1])
                arr[k][j] = arr[w][j - 1] + 1;
            else
            {
                arr[k][j] = max(arr[k][j - 1], arr[w][j]);
            }
        }
    }
    return 0;
}

int main(void)
{
    init();
    LCS();
    printf("%d\n", arr[len1 % 2][len2]);
}