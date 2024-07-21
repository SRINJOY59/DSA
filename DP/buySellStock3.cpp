#include<bits/stdc++.h>
using namespace std;

int solve(int index, int buy, int transactions, vector<int>&prices, int n, vector<vector<vector<int>>>&dp){
    if(transactions == 0){
        return 0;
    }
    if(index >= n){
        return 0;
    }
    if(dp[index][transactions][buy] != -1){
        return dp[index][transactions][buy];
    }
    if(buy){
        int include = -prices[index] + solve(index+1, 1-buy, transactions, prices, n,dp);
        int exclude = solve(index+1, buy, transactions, prices, n, dp);
        dp[index][transactions][buy] =  max(include, exclude);
    }
    else{
        int include = prices[index] + solve(index+1, 1-buy, transactions-1, prices, n, dp);
        int exclude = solve(index+1, buy, transactions, prices, n, dp);
        dp[index][transactions][buy] = max(include, exclude);
    }
    return dp[index][transactions][buy];
}

int main(){
    int n;
    cin>>n;
    vector<int>cost(n);
    for(int i = 0;i<n;i++){
        cin>>cost[i];
    }
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
    // int ans = solve(0, 1, 2, cost, n, dp);
    // cout<<ans<<"\n";

    for(int index = n-1;index>=0;index--){
        for(int transactions = 1;transactions <= 2;transactions++){
            for(int buy = 1;buy>=0;buy--){
                if(buy){
                int include = -cost[index] + dp[index+1][transactions][1-buy];
                int exclude = dp[index+1][transactions][buy];
                dp[index][transactions][buy] =  max(include, exclude);
            }
            else{
                int include = cost[index] + dp[index+1][transactions-1][1-buy];
                int exclude = dp[index+1][transactions][buy];
                dp[index][transactions][buy] = max(include, exclude);
                }
            }
        }
    }
    cout<<dp[0][2][1]<<endl;
    return 0;
}