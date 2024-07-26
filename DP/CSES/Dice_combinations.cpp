#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(int n, vector<int>&dp){
    if(n == 0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans += solve(n-i, dp);
    }

    return dp[n] = ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=min(i, 6);j++){
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }

    cout<<dp[n];
    return 0;
}