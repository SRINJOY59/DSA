#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>cost(n);
    for(int i = 0;i<n;i++){
        cin>>cost[i];
    }
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
    // int ans = solve(0, 1, 2, cost, n, dp);
    // cout<<ans<<"\n";

    for(int index = n-1;index>=0;index--){
        for(int transactions = 1;transactions <= k;transactions++){
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
    cout<<dp[0][k][1]<<endl;
    return 0;
}