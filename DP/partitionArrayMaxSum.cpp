#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k, int i, int n, vector<int> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int maxi = -1;
    int maxVal = -1;
    for (int j = i; j < i + k && j < n; j++)
    {
        maxVal = max(maxVal, arr[j]);
        int sum = (j - i + 1) * maxVal + solve(arr, k, j + 1, n, dp);
        maxi = max(maxi, sum);
    }
    return dp[i] = maxi;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    // return solve(arr, k, 0, n, dp);
    for (int i = n - 1; i >= 0; i--)
    {
        int maxVal = -1;
        int maxi = -1;
        for (int j = i; j < i + k && j < n; j++)
        {
            maxVal = max(maxVal, arr[j]);
            int sum = (j - i + 1) * maxVal + dp[j + 1];
            maxi = max(maxi, sum);
        }
        dp[i] = maxi;
    }
    return dp[0];
}