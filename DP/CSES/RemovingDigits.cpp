#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>&dp){

    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 1e9;
    int temp = n;
    while(temp > 0){
        int rem = temp%10;
        temp /= 10;
        if(rem != 0)
            ans = min(ans, solve(n - rem, dp)+1);
    }
    return dp[n] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    cout<<solve(n, dp);
    return 0;
}