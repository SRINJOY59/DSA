#include <bits/stdc++.h>
using namespace std;


//make the array sorted so that arr[i]%arr[j] where j < i
vector<int> largestDivisibleSubset(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    int lastIndex = 0;
    int maxi = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (((arr[prev] % arr[i] == 0) || (arr[i] % arr[prev] == 0)) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    while (hash[lastIndex] != lastIndex)
    {
        lis.push_back(arr[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    lis.push_back(arr[lastIndex]);
    reverse(lis.begin(), lis.end());
    return lis;
}

