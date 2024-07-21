#include <bits/stdc++.h>
using namespace std;

int minimumMountainRemovals(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp1(n, 1);
    // vector<int> hash(n, 0);

    for (int i = 0; i < n; i++)
    {
        // hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
                // hash[i] = prev;
            }
        }
    }
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[i] > arr[prev] && 1 + dp2[prev] > dp2[i])
            {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp1[i] > 1 && dp2[i] > 1)
        {
            maxi = max(dp1[i] + dp2[i] - 1, maxi);
        }
    }
    int ans = n - maxi; //ths is for removing elements which are not required for creating bitonic sequence
    //actual result is ans
    return ans;
}