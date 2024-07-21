#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int n, int transaction, int index, int buy, vector<vector<int>> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    if (buy)
    {
        int take = -prices[index] + solve(prices, n, transaction, index + 1, 1 - buy, dp);
        int notTake = solve(prices, n, transaction, index + 1, buy, dp);
        dp[index][buy] = max(take, notTake);
    }
    else
    {
        int take = prices[index] - transaction + solve(prices, n, transaction, index + 1, 1 - buy, dp);
        int notTake = solve(prices, n, transaction, index + 1, buy, dp);
        dp[index][buy] = max(take, notTake);
    }
    return dp[index][buy];
}

//space optimization

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    // vector<vector<int>>dp(n, vector<int>(2, -1));
    // return solve(prices, n, fee, 0,1,dp);
    // int n = prices.size();
    // vector<vector<int>>dp(n+2, vector<int>(2, 0));
    // return solve(prices, n, 0, 1, dp);
    vector<int> prev(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int take = -prices[index] + prev[1 - buy];
                int notTake = prev[buy];
                curr[buy] = max(take, notTake);
            }
            else
            {
                int take = prices[index] - fee + prev[1 - buy];
                int notTake = prev[buy];
                curr[buy] = max(take, notTake);
            }
        }
        prev = curr;
    }
    return prev[1];
}
// tabulation

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int take = -prices[index] + dp[index + 1][1 - buy];
                int notTake = dp[index + 1][buy];
                dp[index][buy] = max(take, notTake);
            }
            else
            {
                int take = prices[index] - fee + dp[index + 1][1 - buy];
                int notTake = dp[index + 1][buy];
                dp[index][buy] = max(take, notTake);
            }
        }
    }
    return dp[0][1];
}