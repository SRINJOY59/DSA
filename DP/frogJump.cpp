#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    //space optimised approach

    int prev2 = 0;
    int prev1 = abs(arr[1] - arr[0]);
    for(int i = 2;i<n;i++){
        int curr = min(prev1+abs(arr[i]-arr[i-1]),prev2+abs(arr[i]-arr[i-2]));
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<dp[n-1]<<" "<<prev1<<endl;
    return 0;
}