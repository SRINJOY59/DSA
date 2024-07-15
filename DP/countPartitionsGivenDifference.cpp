#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin>>n>>d;
    vector<int>arr(n);
    int sum  = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum - d < 0 || (sum - d)%2 != 0){
        cout<<0<<endl;
    }
    int target = (sum - d)/2;
    vector<vector<int>>dp(n, vector<int>(target + 1, 0));
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= target){
        dp[0][arr[0]] += 1;
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(arr[i] <= j){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take + notTake;
        }
    }

    cout<<dp[n-1][target]<<endl;
    return 0;
}