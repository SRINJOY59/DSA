#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, vector<vector<int>>&dp){
    if(a == 0 || b == 0){
        return 0;
    }
    if(a == b){
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    int mini = INT_MAX;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1;i<a;i++){
        if(a - i > 0){
            sum1 = 1 + solve(i, b, dp) + solve(a - i, b, dp);
        }
        mini = min(mini, sum1);
    }

    for(int j = 1;j<b;j++){
        if(b - j > 0)
            sum2 = 1 + solve(a, j, dp) + solve(a, b - j, dp);
        mini = min(mini, sum2);
    }
    return mini;
}

int main(){
    int a, b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1, vector<int>(b+1, INT_MAX));
    // cout<<solve(a, b, dp);
    int mini = INT_MAX;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; 
            } else if (i == j) {
                dp[i][j] = 0; 
            } else {
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    cout<<dp[a][b];
    return 0;
}