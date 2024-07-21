#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
{
    if (j - i <= 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int steps = cuts[j] - cuts[i] + solve(cuts, i, k, dp) + solve(cuts, k, j, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    int sz = cuts.size();
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(sz, vector<int>(sz, -1));
    return solve(cuts, 0, sz - 1, dp);
}