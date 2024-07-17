#include <bits/stdc++.h>
using namespace std;
int solve(int i1, int i2, string s, string t, vector<vector<int>> &dp)
{
    if (i1 < 0)
    {
        return i2 + 1;
    }
    if (i2 < 0)
    {
        return i1 + 1;
    }
    if (dp[i1][i2] != -1)
    {
        return dp[i1][i2];
    }
    if (s[i1] == t[i2])
    {
        dp[i1][i2] = solve(i1 - 1, i2 - 1, s, t, dp);
    }
    else
    {
        dp[i1][i2] = 1 + min(min(solve(i1 - 1, i2, s, t, dp), solve(i1, i2 - 1, s, t, dp)), solve(i1 - 1, i2 - 1, s, t, dp));
    }
    return dp[i1][i2];
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    if (m > n)
    {
        swap(word1, word2);
        swap(n, m);
    }
    // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    // // return solve(n-1, m-1, word1, word2, dp);
    // for(int i = 1;i<=m;i++){
    //     dp[0][i] = i;
    // }
    // for(int i = 1;i<=n;i++){
    //     dp[i][0] = i;
    // }
    vector<int> prev(m + 1, 0);
    for (int i = 0; i <= m; i++)
    {
        prev[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min(min(prev[j - 1], prev[j]), curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(n-1, m-1, word1, word2, dp);
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}