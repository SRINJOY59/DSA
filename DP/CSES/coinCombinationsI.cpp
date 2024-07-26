#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
int solve(vector<int>&arr, int target, int n){
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }
    int ways = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] <= target){
            ways += solve(arr, target - arr[i], n);
        }
    }
    return ways;
}

int main(){
    ll n, target;
    cin>>n>>target;
    vector<ll>coins(n);
    for(ll i = 0;i<n;i++){
        cin>>coins[i];
    }
    // cout<<solve(coins, target, n);
    vector<ll>dp(target+1, 0);
    dp[0] = 1;
    for(ll i = 1;i<=target;i++){
        for(ll j = 0;j<n;j++){
            if(coins[j] <= i){
                dp[i] = (dp[i] +  dp[i - coins[j]])%MOD;
            }
        }
    }
    cout<<dp[target];
    return 0;
}