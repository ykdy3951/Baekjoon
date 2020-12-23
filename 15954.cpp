#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, k, arr[505];
    long double min = 999999999999999999;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = i + k - 1; j < n; j++)
        {
            long double mean = 0;
            for (int l = i; l <= j; l++)
                mean += arr[l];
            mean /= (long double)(j - i + 1);
            long double sd = 0;
            for (int l = i; l <= j; l++)
                sd += (arr[l] - mean) * (arr[l] - mean);
            sd /= (long double)(j - i + 1);
            min = min > sd ? sd : min;
        }
    }
    cout.precision(11);
    cout << sqrt(min);
}