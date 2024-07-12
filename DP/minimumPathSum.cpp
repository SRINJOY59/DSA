#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            else{
                int left = 1e9;
                int up = 1e9;
                if(i > 0){
                    up = dp[i-1][j] + arr[i][j];
                }
                if(j > 0){
                    left = dp[i][j-1] + arr[i][j];
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    cout<<dp[n-1][m-1]<<"\n";

    //space optimised version

    vector<int>prev(m, 0);
    for(int i = 0;i<n;i++){
        vector<int>curr(m, 0);
        for(int j = 0;j<m;j++){
            if(i == 0 && j == 0){
                curr[j] = arr[i][j];
            }
            else{
                int left = 1e9;
                int up = 1e9;
                if(i > 0){
                    up = prev[j] + arr[i][j];
                }
                if(j > 0){
                    left = curr[j-1] + arr[i][j]; 
                }
                curr[j] = min(left, up);
            }
        }
        prev = curr;
    }
    cout<<prev[m-1]<<"\n";
    return 0;
}