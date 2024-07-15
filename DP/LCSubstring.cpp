#include<bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i] == str2[j]) {
        ans = 1 + solve(str1, str2, i - 1, j - 1, dp);
    } else {
        ans = 0;
    }
    return dp[i][j] = ans;
}

int lcs(string &str1, string &str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    int maxLen = 0;  
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}