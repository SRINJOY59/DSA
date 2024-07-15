//we can choose one coin any number of time and make the sum as target

#include<bits/stdc++.h>
using namespace std;

int solve(int index, int target, vector<int>&num, vector<vector<int>>&dp){
    if(index < 0){
        return INT_MAX;  
    }
    
    if(target == 0){
        return 0;  
    }
    if(dp[index][target] != -1)
        return dp[index][target];
    if(index == 0){
        if(target%num[index] == 0){
            return (target/num[index]);
        }
        else{
            return 1e9;
        }
    }
    int notTake = solve(index - 1, target, num, dp);
    int take = 1e9;
    if(num[index] <= target)
        take = 1 + solve(index, target - num[index], num, dp);
    int ans = min(notTake, take);
    dp[index][target] = ans;
    return ans;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1, 0));
    for(int target = 0;target<=x;target++){
        if(target%num[0] == 0)
            dp[0][target] = target/num[0];
        else
            dp[0][target] = 1e9;
    }
    for(int i = 1;i<n;i++){
        for(int target = 0;target<=x;target++){
            int notTake = dp[i - 1][target];
            int take = 1e9;
            if(num[i] <= target)
                take = 1 + dp[i][target - num[i]];
            int ans = min(notTake, take);
            dp[i][target] = ans;
        }
    }
    return dp[n-1][x]!=1e9?dp[n-1][x]:-1;
}