#include<bits/stdc++.h>
using namespace std;

int solve(int index, vector<int>&arr, int limit, int n, vector<vector<int>>&dp){
    if(index >= n){
        return 0;
    }
    if(limit < 0){
        return 0;
    }
    if(dp[index][limit] != -1){
        return dp[index][limit];
    }
    int take = 0;
    int notTake = 0;
    if(arr[index] <= limit){
        take = 1 + solve(index+1, arr, limit - arr[index], n, dp);
    }
    notTake = solve(index+1, arr, limit, n, dp);
    int ans = max(take, notTake);
    dp[index][limit] = ans;
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(n, vector<int>(m+1, -1));
    int ans = solve(0, arr, m, n, dp);
    cout<<ans<<endl;
    return 0;
}