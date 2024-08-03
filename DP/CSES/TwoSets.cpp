#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(vector<int>&arr, int n, int sum, int index, vector<vector<int>>&dp){
    if(sum == 0){
        return 1;
    }
    
    if(index >= n || sum < 0){
        return 0;
    }
    if(dp[index][sum] != -1){
        return dp[index][sum];
    }
    
    int take = solve(arr, n, sum - arr[index], index+1, dp);
    int notTake = solve(arr, n, sum, index+1, dp);
    return dp[index][sum] = (take + notTake)%MOD;
}
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    int sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << 0 << endl; 
        return 0;
    }
    sum = sum/2;
    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i = n-1;i>=1;i--){
        for(int s = 0;s<=sum;s++){
            int take = 0;
            if(s >= arr[i])
                take = dp[i+1][s - arr[i]];
            int notTake = dp[i+1][s];
            dp[i][s] = (take + notTake)%MOD;
        }
    }
    int ans = dp[1][sum];
    cout<<ans<<endl;
    return 0;
}