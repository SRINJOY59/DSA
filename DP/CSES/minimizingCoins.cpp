#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins, int n, int x, int index, vector<vector<int>>&dp){
    if(x == 0){
        return 0;
    }
    if(index == 0){
        if(x%coins[0] == 0){
            return (x/coins[0]);
        }
        else{
            return 1e9;
        }
    }
    if(dp[index][x] != -1){
        return dp[index][x];
    }
    int notTake = solve(coins, n, x, index-1, dp);
    int take = 1e9;
    if(coins[index] <= x){
        take = 1 + solve(coins, n, x-coins[index], index, dp);
    }
    int ans = min(notTake, take);
    dp[index][x] = ans;
    return ans;
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    // vector<vector<int>>dp(n, vector<int>(x+1, 0));
    // cout<<solve(coins, n, x, n-1, dp);
    vector<int>prev(x+1, 0);
    for(int target = 0;target <= x;target++){
        if(target%coins[0] == 0){
            prev[target] = target/coins[0];
        }
        else{
            prev[target] = 1e9;
        }
    }
    for(int i = 1;i<n;i++){
        vector<int>curr(x+1, 0);
        for(int target = 0;target <= x;target++){
            int notTake = prev[target];
            int take = 1e9;
            if(coins[i] <= target){
                take = 1 + curr[target - coins[i]];
            }
            int ans = min(notTake, take);
            curr[target] = ans;
        }
        prev = curr;
    }
    int ans = prev[x];
    if(ans == 1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}