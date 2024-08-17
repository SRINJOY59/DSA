#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n, int index, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (index >= 3)
    {
        return INT_MIN;
    }
    if (dp[n][index] != -1)
    {
        return dp[n][index];
    }
    int take_stay = INT_MIN;
    int notTake = INT_MIN;
    if (arr[index] <= n)
    {
        take_stay = 1 + solve(arr, n - arr[index], index, dp);
    }
    notTake = solve(arr, n, index + 1, dp);
    dp[n][index] = max(take_stay, notTake);
    return dp[n][index];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0; // Base case: 0

    vector<int> arr = {x, y, z};

    for (int i = 0; i < 3; i++)
    {
        for (int total = arr[i]; total <= n; total++)
        {
            if (dp[total - arr[i]] != INT_MIN)
            {
                dp[total] = max(dp[total], 1 + dp[total - arr[i]]);
            }
        }
    }
    return dp[n] < 0 ? 0 : dp[n];
}