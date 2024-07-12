#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for(int i = 2;i<n;i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }

    cout<<dp[n-1]<<" ";
    return 0;
}