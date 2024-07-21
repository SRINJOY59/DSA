#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int maxi = -1;
    for (int k = i; k <= j; k++)
    {
        int cost = nums[i - 1] * nums[k] * nums[j + 1] + solve(nums, i, k - 1, n, dp) + solve(nums, k + 1, j, n, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = -1;
            for (int k = i; k <= j; k++)
            {
                int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    // return solve(nums, 1, n, n, dp);
    return dp[1][n];
}