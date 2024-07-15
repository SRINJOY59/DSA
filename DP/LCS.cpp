#include <bits/stdc++.h>
using namespace std;

int solve(string text1, string text2, int index1, int index2, vector<vector<int>> &dp)
{
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    if (text1[index1] == text2[index2])
    {
        dp[index1][index2] = 1 + solve(text1, text2, index1 - 1, index2 - 1, dp);
    }
    else
    {
        dp[index1][index2] = max(solve(text1, text2, index1 - 1, index2, dp), solve(text1, text2, index1, index2 - 1, dp));
    }
    return dp[index1][index2];
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (text1[ind1 - 1] == text2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    //for printing
    int len = dp[n][m];
    string ans = "";
    int index = len - 1;
    for(int i = 0;i<len;i++){
        ans += "$";
    }
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            ans[index] = text1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<"string is: "<<ans<<endl;
    return dp[n][m];
    //return dp[n-1][m-1];
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int length = longestCommonSubsequence(s1,s2);
    cout<<length<<endl;
    return 0;
}