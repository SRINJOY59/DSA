#include<bits/stdc++.h>
using namespace std;

int solve(int index, int j1, int j2, int r,int c, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
    if(j1 < 0||j2 < 0||j1 >= c || j2 >= c){
        return -1e9;
    }
    if(index == r - 1){
        if(j1 == j2){
            return grid[index][j1];
        }
        else{
            return grid[index][j1] + grid[index][j2];
        }
    }
    if(dp[index][j1][j2] != -1){
        return dp[index][j1][j2];
    }
    int maxi = -1e9;
    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            int val = 0; 
            if(j1 == j2){
                val = grid[index][j1] + solve(index+1, j1+i, j2+j,r, c, grid, dp);
            }
            else{
                val = grid[index][j1] + grid[index][j2] + solve(index+1, j1+i, j2+j,r, c, grid, dp);
            }
            maxi = max(val, maxi);
        }
    }
    dp[index][j1][j2] = maxi;
    return dp[index][j1][j2];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c-1,r, c, grid, dp);
}

int main(){
    int r, c;
    cin>>r>>c;
    vector<vector<int>>grid(r, vector<int>(c, 0));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    int m = c;
    for(int j1 = 0;j1<m;j1++){
        for(int j2 = 0;j2<m;j2++){
            if(j1 == j2){
                dp[r-1][j1][j2] = grid[r-1][j2];
            }
            else{
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }
    }
    // int m = c;
    for(int i = r-2;i>=0;i--){
        for(int j1 = 0;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                int maxi = -1e9;
                for(int dj1 = -1;dj1<=1;dj1++){
                    for(int dj2 = -1;dj2<=1;dj2++){
                        int val = 0; 
                        if(j1 == j2){
                            if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < m)
                                val = grid[i][j1] + dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < m)
                                val = grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2];
                        }
                        maxi = max(val, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    vector<vector<vector<int>>>dp1(r, vector<vector<int>>(c, vector<int>(c, -1)));
    cout<<dp[0][0][c-1]<<" "<<solve(0, 0, c-1, r, c, grid, dp1)<<endl;
    return 0;
}