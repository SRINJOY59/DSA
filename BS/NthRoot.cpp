#include <bits/stdc++.h>
using namespace std;
long long check(int val, int n, int m)
{
    long long prod = 1;
    for (int i = 1; i <= n; i++)
    {
        prod = prod * val;
        if (prod > m)
        {
            return prod;
        }
    }
    return prod;
}
int NthRoot(int n, int m)
{
    // Code here.
    int start = 1;
    int end = m;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (check(mid, n, m) == m)
        {
            ans = mid;
            break;
        }
        else if (check(mid, n, m) > m)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}