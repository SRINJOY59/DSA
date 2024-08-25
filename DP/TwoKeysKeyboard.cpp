#include <bits/stdc++.h>
using namespace std;

// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

int solve(int n, int length, int copied, vector<vector<int>> &dp)
{
    if (length >= n)
    {
        return 0;
    }
    if (dp[length][copied] != -1)
    {
        return dp[length][copied];
    }
    if (n % length == 0)
    {
        return 2 + solve(n, length + length, length, dp);
    }
    else
    {
        return 1 + solve(n, length + copied, copied, dp);
    }
}
int minSteps(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(n, 1, 1, dp);
}

// mathematical solution

int minSteps(int n)
{
    int ans = 0;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ans += i;
            n = n / i;
        }
    }
    if (n > 1)
    {
        ans += n;
    }
    return ans;
}