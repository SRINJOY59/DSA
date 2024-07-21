#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int x;
    cin >> x;
    if (x == 0 || x == 1)
    {
        cout << x << endl;
        return 0;
    }
    long long start = 1;
    long long end = x / 2;
    int ans = -1;
    long long mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (mid * mid == x)
        {
            ans = mid;
            break;
        }
        else if (mid * mid > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            ans = mid;
        }
        mid = start + (end - start) / 2;
    }
    cout << ans << endl;
    return 0;
}