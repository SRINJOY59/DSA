#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, int w, vector<int>&profit, vector<int>&weight, vector<vector<int>>&dp){
    if(w == 0){
        return 0;
    }
    if(index < 0 || w < 0){
        return 0;
    }
    
    if(dp[index][w] != -1){
        return dp[index][w];
    }
    int take = 0;
    if(weight[index] <= w){
        take = profit[index] + solve(index, n, w - weight[index], profit, weight, dp);
    }
    int notTake = solve(index-1, n, w, profit, weight, dp);
    int ans = max(take, notTake);
    dp[index][w] = ans;
    return ans;
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n, vector<int>(w+1, 0));
    // return solve(n-1, n, w, profit, weight, dp);
    for(int i = 0;i<=w;i++){
        if(i >= weight[0]){
            dp[0][i] = (i/weight[0])*profit[0];
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=w;j++){
            int take = 0;
            if(weight[i] <= j){
                take = profit[i] + dp[i][j - weight[i]];
            }
            int notTake = dp[i-1][j];
            int ans = max(take, notTake);
            dp[i][j] = ans;
        }
    }
    return dp[n-1][w];
}