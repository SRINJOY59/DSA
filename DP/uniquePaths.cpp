#include <bits/stdc++.h>
using namespace std;
//unique paths to reach (0, 0) to (m-1, n-1)
int solve(int index1, int index2, int m, int n, vector<vector<int>> &dp)
{
    if (index1 == m - 1 && index2 == n - 1)
    {
        return 1;
    }
    if (index1 >= m || index2 >= n)
    {
        return 0;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    int right = solve(index1 + 1, index2, m, n, dp);
    int down = solve(index1, index2 + 1, m, n, dp);
    int ans = right + down;
    dp[index1][index2] = ans;
    return dp[index1][index2];
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int right = 0;
            int down = 0;
            if (i == m - 1 && j == n - 1)
            {
                continue;
            }
            if (i < m - 1)
            {
                right = dp[i + 1][j];
            }
            if (j < n - 1)
            {
                down = dp[i][j + 1];
            }
            dp[i][j] = right + down;
        }
    }
    return dp[0][0];
}