#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &piles, int index, int type, int n, vector<int> &prefix, vector<vector<int>> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index][type] != -1)
    {
        return dp[index][type];
    }

    if (type == 0)
    { // Alice's turn
        int maxi = INT_MIN;
        for (int i = 0; i <= 2; i++)
        {
            if (index + i < n)
            {
                int currentSum = prefix[index + i] - (index > 0 ? prefix[index - 1] : 0);
                maxi = max(maxi, currentSum + solve(piles, index + i + 1, 1, n, prefix, dp));
            }
        }
        return dp[index][type] = maxi;
    }
    else
    { // Bob's turn
        int mini = INT_MAX;
        for (int i = 0; i <= 2; i++)
        {
            if (index + i < n)
            {
                int currentSum = prefix[index + i] - (index > 0 ? prefix[index - 1] : 0);
                mini = min(mini, solve(piles, index + i + 1, 0, n, prefix, dp));
            }
        }
        return dp[index][type] = mini;
    }
}
string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    vector<int> prefix(n);
    prefix[0] = stoneValue[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + stoneValue[i];
    }
    int alice = solve(stoneValue, 0, 0, n, prefix, dp);
    int bob = prefix[n - 1] - alice;

    if (alice > bob)
    {
        return "Alice";
    }
    else if (alice == bob)
    {
        return "Tie";
    }
    else
    {
        return "Bob";
    }
}