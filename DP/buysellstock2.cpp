#include <bits/stdc++.h>
using namespace std;

int solve(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
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
        int include = -prices[index] + solve(index + 1, 1 - buy, prices, n, dp);
        int exclude = solve(index + 1, buy, prices, n, dp);
        dp[index][buy] = max(include, exclude);
    }
    else
    {
        int include = prices[index] + solve(index + 1, 1 - buy, prices, n, dp);
        int exclude = solve(index + 1, buy, prices, n, dp);
        dp[index][buy] = max(include, exclude);
    }
    return dp[index][buy];
}
int maxProfit(vector<int> &prices)
{
    // int n = prices.size();
    // vector<vector<int>>dp(n+1, vector<int>(2, 0));
    // // return solve(0, 1, prices, n, dp);
    // for(int i = n-1;i>=0;i--){

    //         int include = -prices[i] + dp[i+1][1];
    //         int exclude = dp[i+1][0];
    //         dp[i][0] = max(include, exclude);

    //         include = prices[i] + dp[i+1][0];
    //         exclude = dp[i+1][1];
    //         dp[i][1] = max(include, exclude);

    // }
    // return dp[0][0];
    int n = prices.size();
    vector<long> prev(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<long> curr(2, 0);
        long include = -prices[i] + prev[1];
        long exclude = prev[0];
        curr[0] = max(include, exclude);

        include = prices[i] + prev[0];
        exclude = prev[1];
        curr[1] = max(include, exclude);
        prev = curr;
    }
    return prev[0];
}