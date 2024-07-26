#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<vector<char>>&mat, int i, int j, int n, vector<vector<int>>&dp){

    if(i >= n || j >= n){
        return 0;
    }

    if(mat[i][j] == '*'){
        return 0;
    }
    

    if(i == n-1 && j == n-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    

    int right = solve(mat, i+1, j, n, dp);
    int down = solve(mat, i, j+1, n, dp);

    return right + down;
}



int main(){
    int n;
    cin>>n;
    vector<vector<char>>mat(n, vector<char>(n));
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    // cout<<solve(mat, 0, 0, n, dp);

    if(mat[n-1][n-1] == '*' || mat[0][0] == '*'){
        cout<<0<<endl;
        return 0;
    }

    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            if(i == n-1 && j == n-1){
                dp[i][j] = 1;
            }
            else if(mat[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                int right = dp[i+1][j];
                int down = dp[i][j+1];

                dp[i][j] = (right + down)%MOD;
            }
        }
    }

    cout<<dp[0][0];
    return 0;
}