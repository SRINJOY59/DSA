#include<bits/stdc++.h>
using namespace std;

int solve(int index, int n, int x, vector<int>&h, vector<int>&s, vector<vector<int>>&dp){
    if(index == n) return 0;
    if(x == 0) return 0;
    if(x < 0) return -1e9;

    if(dp[index][x] != -1){
        return dp[index][x];
    }

    int notTake = solve(index+1, n, x, h, s, dp);
    int take = INT_MIN;
    if(x >= h[index])
        take = s[index] + solve(index+1, n, x - h[index], h, s, dp);

    return dp[index][x] = max(take, notTake);
}
int main(){
    int n, x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<int>prev(x+1, 0);
    vector<int>curr(x+1, 0);
    // vector<vector<int>>dp(n+1, vector<int>(x+1, 0));
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<=x;j++){
            int notTake = prev[j];
            int take = INT_MIN;
            if(j >= h[i])
                take = s[i] + prev[j-h[i]];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
    // cout<<solve(0, n, x, h, s, dp);

    return 0;
}