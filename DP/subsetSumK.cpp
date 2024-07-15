#include<bits/stdc++.h>
using namespace std;


bool solve(int n,int index, vector<int>&arr, int k, vector<vector<int>>&dp){
    if(k == 0){
        return true;
    }
    if(index >= n){
        return false;
    }
    if(dp[index+1][k] != -1){
        return dp[index+1][k];
    }
    bool take = false;
    bool notTake = false;
    if(k >= arr[index]) 
        take = solve(n,index + 1, arr, k - arr[index], dp);
    notTake = solve(n, index+1, arr, k, dp);
    return dp[index+1][k] = take||notTake;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<vector<int>>dp(n, vector<int>(k+1, 0));
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int target=1;target<=k;target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if(arr[i] <= target){
                take = dp[i-1][target-arr[i]];
            }
            dp[i][target] = take or notTake;
        }
    }
    //space optimised verison
    vector<int>prev(k+1, 0);
    vector<int>curr(k+1, 0);
    prev[0] = curr[0] = 1;
    if (arr[0] <= k) {
        prev[arr[0]] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int target = 1;target<=k;target++){
            bool take = false;
            bool notTake = false;
            if(target >= arr[i]){
                take = prev[target-arr[i]];
            }
            
            notTake = prev[target];
            curr[target] = take|notTake;
        }
        prev = curr;
    }
    cout<<dp[n-1][k]<<" "<<prev[k]<<endl;
    return 0;
}