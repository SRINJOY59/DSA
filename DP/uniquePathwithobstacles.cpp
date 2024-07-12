#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>mat(n, vector<int>(m, -1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m, -1));
    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
            if(i == n-1 && j == m-1){
                dp[i][j] = 1;
            }
            else if(mat[i][j] == -1){
                dp[i][j] = 0;
            }
            else{
                int right = 0;
                int down = 0;
                if(i < n-1){
                    right = dp[i+1][j];
                }
                if(j < m-1){
                    down = dp[i][j+1];
                }
                dp[i][j] = right + down;
            }
        }
    }
    cout<<dp[0][0]<<"\n";

    //space optimised approach

    vector<int>prev(m, 0);
    for(int i = n-1;i>=0;i--){
        vector<int>curr(m, 0);
        for(int j = m-1;j>=0;j--){
            if(i == n-1 && j == m-1){
                curr[j] = 1;
            }
            else if(mat[i][j] == -1){
                curr[j] = 0;
            }
            else{
                int right = 0;
                int down = 0;
                if(i < n-1){
                    right = prev[j];
                }
                if(j < m-1){
                    down = curr[j+1];
                }
                curr[j] = right + down;
            }
        }
        prev = curr;
    }
    cout<<prev[0]<<"\n";
    return 0;
}