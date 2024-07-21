#include <bits/stdc++.h>
using namespace std;

//memoization

int solve(vector<int> &prices, int n, int index, int buy, vector<vector<int>> &dp)
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
        int take = -prices[index] + solve(prices, n, index + 1, 1 - buy, dp);
        int notTake = solve(prices, n, index + 1, buy, dp);
        dp[index][buy] = max(take, notTake);
    }
    else
    {
        int take = prices[index] + solve(prices, n, index + 2, 1 - buy, dp);
        int notTake = solve(prices, n, index + 1, buy, dp);
        dp[index][buy] = max(take, notTake);
    }
    return dp[index][buy];
}


//tabulation

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        // return solve(prices, n, 0, 1, dp);
        for(int index = n-1;index >= 0;index--){
                for(int buy = 0;buy<=1;buy++){
                    if(buy){
                        int take = -prices[index] + dp[index+1][1-buy];
                        int notTake = dp[index+1][buy];
                        dp[index][buy] =  max(take, notTake);
                    }
                    else{
                        int take = prices[index] + dp[index+2][1-buy];
                        int notTake = dp[index+1][buy];
                        dp[index][buy] = max(take, notTake);
                    }
            }
        }
        return dp[0][1];
    }



//space optimised version
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // return solve(prices, n, 0, 1, dp);
    vector<int> prev1(2, 0);
    vector<int> prev2(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int take = -prices[index] + prev1[1 - buy];
                int notTake = prev1[buy];
                curr[buy] = max(take, notTake);
            }
            else
            {
                int take = prices[index] + prev2[1 - buy];
                int notTake = prev1[buy];
                curr[buy] = max(take, notTake);
            }
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1[1];
}