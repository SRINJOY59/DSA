#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i < 0 && j >= 0)
    {
        bool flag = true;
        for (int k = j; k >= 0; k--)
        {
            if (t[k] != '*')
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    if (i >= 0 && j < 0)
    {
        bool flag = true;
        for (int k = i; k >= 0; k--)
        {
            if (s[k] != '*')
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == t[j] || s[i] == '?' || t[j] == '?')
    {
        dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    }
    else if (s[i] == '*')
    {
        dp[i][j] = solve(i - 1, j, s, t, dp) | solve(i, j - 1, s, t, dp);
    }
    else if (t[j] == '*')
    {
        dp[i][j] = solve(i, j - 1, s, t, dp) | solve(i - 1, j, s, t, dp);
    }
    return dp[i][j] == -1 ? 0 : dp[i][j];
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return solve(n-1, m-1, s, p, dp);
    dp[0][0] = 1;
    // bool f1 = true;
    // int index = -1;
    for (int i = 1; i <= m; i++)
    {
        if (p[i - 1] != '*')
        {
            // index = i;
            break;
        }
        else
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] != '*')
        {
            break;
        }
        else
        {
            dp[i][0] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?' || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
        }
    }
    return dp[n][m] == -1 ? 0 : dp[n][m];
}