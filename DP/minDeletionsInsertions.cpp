#include <bits/stdc++.h>
using namespace std;

//variation of edit distance where only insertion and deletion allowed

int solve(int index1, int index2, string str1, string str2, vector<vector<int>> &dp)
{
    if (index1 >= str1.length())
    {
        return str2.length() - index2;
    }
    if (index2 >= str2.length())
    {
        return str1.length() - index1;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    if (str1[index1] == str2[index2])
    {
        return dp[index1][index2] = solve(index1 + 1, index2 + 1, str1, str2, dp);
    }
    else
    {
        return dp[index1][index2] = 1 + min(solve(index1 + 1, index2, str1, str2, dp), solve(index1, index2 + 1, str1, str2, dp));
    }
}
int minOperations(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, str1, str2, dp);
}