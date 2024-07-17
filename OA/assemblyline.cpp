#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>A, vector<int>B, int X, int Y, int index, int n, int check, vector<vector<int>>&dp){
    if(index < 0){
        return 0;
    }
    int same = INT_MAX;
    int change = INT_MAX;
    if(dp[index][check] != -1){
        return dp[index][check];
    }
    if(check == 0){
        same = A[index] + solve(A, B, X, Y, index-1, n, check, dp);
        change = A[index] + X + solve(A, B, X, Y, index-1, n, 1 - check, dp);
    }
    else{
        same = B[index] + solve(A, B, X, Y, index-1, n, check, dp);
        change = B[index] + Y + solve(A, B, X, Y, index-1, n, 1 - check, dp);
    }
    dp[index][check] = min(same, change);
    return min(same, change);
}

int main(){
    int n, X, Y;
    cin>>n>>X>>Y;
    vector<int>A(n), B(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    for(int i = 0; i < n; i++){
        cin>>B[i];
    }
    // vector<vector<int>>dp(n, vector<int>(2, -1));
    // cout<<solve(A, B, X, Y, 0, n, 0, dp)<<endl;
    vector<int>prev(2, 0);
    prev[0] = A[0];
    prev[1] = B[0];
    vector<int>curr(2, 0); 
    for (int i = 1; i < n; ++i) {
        curr[0] = min(prev[0] + A[i], prev[1] + A[i] + Y);
        curr[1] = min(prev[1] + B[i], prev[0] + B[i] + X);
        prev = curr;
    }
    cout<<min(curr[0], curr[1]);
   
    return 0;
}