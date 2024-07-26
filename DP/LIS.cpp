#include <bits/stdc++.h>
using namespace std;

int solve(int index, int prevIndex, int arr[], int n, vector<vector<int>> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index][prevIndex + 1] != -1)
    {
        return dp[index][prevIndex + 1];
    }
    int take = 0;
    int notTake = solve(index + 1, prevIndex, arr, n, dp);
    if (prevIndex == -1 || arr[index] > arr[prevIndex])
    {
        take = 1 + solve(index + 1, index, arr, n, dp);
    }
    dp[index][prevIndex + 1] = max(take, notTake);
    return dp[index][prevIndex + 1];
}
// print LIS

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    // Code here
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    int lastIndex = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
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

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {

        for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
        {
            int take = 0;
            int notTake = prev[prevIndex + 1];
            if (prevIndex == -1 || arr[index] > arr[prevIndex])
            {
                take = 1 + prev[index + 1];
            }
            curr[prevIndex + 1] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[0];
}

// most optimised version

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len += 1;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}