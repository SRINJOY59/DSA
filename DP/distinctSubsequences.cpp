#include <bits/stdc++.h>
using namespace std;
int solve(string s, string t, int index1, int index2, vector<vector<int>> &dp)
{
    if (index2 < 0)
        return 1;
    if (index1 < 0)
        return 0;
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    if (s[index1] == t[index2])
    {
        dp[index1][index2] = solve(s, t, index1 - 1, index2 - 1, dp) + solve(s, t, index1 - 1, index2, dp);
    }
    else
    {
        dp[index1][index2] = solve(s, t, index1 - 1, index2, dp);
    }
    return dp[index1][index2];
}
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    // return solve(s, t, n-1, m-1, dp);
    vector<double> prev(m + 1, 0);
    prev[0] = 1;
    vector<double> curr(m + 1, 0);
    for (int index1 = 1; index1 <= n; index1++)
    {

        curr[0] = 1;
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (s[index1 - 1] == t[index2 - 1])
            {
                curr[index2] = prev[index2 - 1] + prev[index2];
            }
            else
            {
                curr[index2] = prev[index2];
            }
        }
        prev = curr;
    }
    return (int)prev[m];
}

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    // return solve(s, t, n-1, m-1, dp);
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (s[index1 - 1] == t[index2 - 1])
            {
                dp[index1][index2] = dp[index1 - 1][index2 - 1] + dp[index1 - 1][index2];
            }
            else
            {
                dp[index1][index2] = dp[index1 - 1][index2];
            }
        }
    }
    return (int)dp[n][m];
}